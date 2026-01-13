/*
 * Solution for OXC Ports Arrangement Problem
 * Fixes: Handled Division by Zero (Exit code -1073741676) when no links are found.
 * Optimization: Two-pass greedy allocation (Fairness -> Throughput) to minimize starvation.
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <random>

using namespace std;

// --- Constants & Globals ---
int N, S, L; // Groups, Spines, Leaves
int M, K, P; // OXCs, Links per OXC-Spine, Planes
int R;       // Ports per OXC

// Mapping helpers
struct PortInfo {
    int group;
    int spine;
    int link;
};

// State Tracking
// adj[m][u] = v implies port u on OXC m is connected to port v
vector<vector<int>> oxc_adj; 

// Helpers to quickly find ports for a specific group on a specific OXC
// group_ports[m][g] gives a list of port indices for group g on oxc m
vector<vector<vector<int>>> group_ports;

// Random Engine
mt19937 rng(1337);

// Precompute Port Information
// Maps linear port index to physical location details
PortInfo get_port_info(int oxc_idx, int port_idx) {
    int S_div_P = S / P;
    int ports_per_group = S_div_P * K;
    
    // Safety check for division
    if (ports_per_group == 0) ports_per_group = 1; 

    int group = port_idx / ports_per_group;
    int rem = port_idx % ports_per_group;
    
    int plane_size = M / P;
    if (plane_size == 0) plane_size = 1;
    int plane = oxc_idx / plane_size;
    
    int spine = (rem / K) + plane * S_div_P;
    int link = rem % K;
    
    return {group, spine, link};
}

// Data structures for routing
struct RoutePath {
    int sA, kA, m, sB, kB;
};

struct FlowDemand {
    int id; 
    int gA, lA, gB, lB;
};

struct LinkUse {
    int oxc;
    int u; 
    int v; 
};

void solve() {
    // I/O Optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> S >> L)) return;
    cin >> M >> K >> P;

    R = N * (S / P) * K;

    // Initialize Topology: -1 means idle
    oxc_adj.assign(M, vector<int>(R, -1));

    // Precompute group ports mapping
    group_ports.assign(M, vector<vector<int>>(N));
    for (int m = 0; m < M; ++m) {
        for (int p_idx = 0; p_idx < R; ++p_idx) {
            PortInfo info = get_port_info(m, p_idx);
            if (info.group < N) {
                group_ports[m][info.group].push_back(p_idx);
            }
        }
    }

    // Process 5 Queries
    for (int q_num = 0; q_num < 5; ++q_num) {
        int Q;
        if (!(cin >> Q)) break;

        vector<FlowDemand> flows(Q);
        map<pair<int,int>, vector<int>> demand_map;

        for (int i = 0; i < Q; ++i) {
            flows[i].id = i;
            cin >> flows[i].gA >> flows[i].lA >> flows[i].gB >> flows[i].lB;
            // Key is always (min, max) to group bidirectional flows
            // Input guarantees gA < gB
            demand_map[{flows[i].gA, flows[i].gB}].push_back(i);
        }

        map<pair<int,int>, vector<LinkUse>> active_links;
        vector<vector<bool>> port_busy(M, vector<bool>(R, false));
        vector<RoutePath> routing_results(Q);

        // --- Phase 1: Reuse Existing Connections ---
        for (auto& [groups, flow_indices] : demand_map) {
            int gA = groups.first;
            int gB = groups.second;
            
            for (int m = 0; m < M; ++m) {
                for (int u : group_ports[m][gA]) {
                    int v = oxc_adj[m][u];
                    if (v != -1) {
                        PortInfo v_info = get_port_info(m, v);
                        if (v_info.group == gB) {
                            port_busy[m][u] = true;
                            port_busy[m][v] = true;
                            active_links[groups].push_back({m, u, v});
                        }
                    }
                }
            }
        }

        // --- Phase 2: Create New Connections (Two-Pass Greedy) ---
        vector<pair<int,int>> group_pairs;
        for(auto const& [key, val] : demand_map) group_pairs.push_back(key);
        
        // Jitter the order to prevent bias/starvation
        shuffle(group_pairs.begin(), group_pairs.end(), rng);

        // Pass 2a: Ensure MINIMUM connectivity (1 link per pair)
        for (auto& groups : group_pairs) {
            if (active_links[groups].empty()) {
                int gA = groups.first;
                int gB = groups.second;
                
                // Try to find ANY free path
                vector<int> oxc_order(M);
                for(int i=0; i<M; ++i) oxc_order[i] = i;
                shuffle(oxc_order.begin(), oxc_order.end(), rng);

                for (int m : oxc_order) {
                    int free_u = -1, free_v = -1;
                    
                    // Strict check: only unused ports
                    for (int u : group_ports[m][gA]) if (!port_busy[m][u] && oxc_adj[m][u] == -1) { free_u = u; break; }
                    for (int v : group_ports[m][gB]) if (!port_busy[m][v] && oxc_adj[m][v] == -1) { free_v = v; break; }
                    
                    // Relaxed check: overwrite idle connections if desperate
                    if (free_u == -1) for (int u : group_ports[m][gA]) if (!port_busy[m][u]) { free_u = u; break; }
                    if (free_v == -1) for (int v : group_ports[m][gB]) if (!port_busy[m][v]) { free_v = v; break; }

                    if (free_u != -1 && free_v != -1) {
                        port_busy[m][free_u] = true;
                        port_busy[m][free_v] = true;
                        active_links[groups].push_back({m, free_u, free_v});
                        break; // Found our 1 mandatory link
                    }
                }
            }
        }

        // Pass 2b: Fill remaining capacity
        for (auto& groups : group_pairs) {
            int gA = groups.first;
            int gB = groups.second;
            size_t needed = demand_map[groups].size();
            
            // Limit search if we already have enough links (e.g., 1:1 ratio is ideal but capped by hardware)
            // Heuristic: Don't exceed 'needed' links.
            if (active_links[groups].size() >= needed) continue;

            vector<int> oxc_order(M);
            for(int i=0; i<M; ++i) oxc_order[i] = i;
            shuffle(oxc_order.begin(), oxc_order.end(), rng);

            for (int m : oxc_order) {
                if (active_links[groups].size() >= needed) break;

                int free_u = -1, free_v = -1;
                // Prioritize truly idle ports first
                for (int u : group_ports[m][gA]) if (!port_busy[m][u] && oxc_adj[m][u] == -1) { free_u = u; break; }
                if (free_u != -1) {
                    for (int v : group_ports[m][gB]) if (!port_busy[m][v] && oxc_adj[m][v] == -1) { free_v = v; break; }
                }

                // If no truly idle ports, cannibalize dead links
                if (free_u == -1) for (int u : group_ports[m][gA]) if (!port_busy[m][u]) { free_u = u; break; }
                if (free_v == -1) for (int v : group_ports[m][gB]) if (!port_busy[m][v]) { free_v = v; break; }

                if (free_u != -1 && free_v != -1) {
                    port_busy[m][free_u] = true;
                    port_busy[m][free_v] = true;
                    active_links[groups].push_back({m, free_u, free_v});
                }
            }
        }

        // --- Phase 3: Update Global Topology State ---
        for (auto const& [groups, links] : active_links) {
            for (auto& link : links) {
                int m = link.oxc;
                int u = link.u;
                int v = link.v;
                
                int old_u_conn = oxc_adj[m][u];
                int old_v_conn = oxc_adj[m][v];
                
                if (old_u_conn != -1 && old_u_conn != v) oxc_adj[m][old_u_conn] = -1; 
                if (old_v_conn != -1 && old_v_conn != u) oxc_adj[m][old_v_conn] = -1;
                
                oxc_adj[m][u] = v;
                oxc_adj[m][v] = u;
            }
        }

        // --- Phase 4: Output ---
        // 1. OXC Config
        for (int m = 0; m < M; ++m) {
            for (int r = 0; r < R; ++r) {
                cout << oxc_adj[m][r] << (r == R - 1 ? "" : " ");
            }
            cout << "\n";
        }

        // 2. Routes
        for (auto& [groups, flow_indices] : demand_map) {
            auto& links = active_links[groups];
            int link_count = links.size();
            
            for (int i = 0; i < flow_indices.size(); ++i) {
                int f_idx = flow_indices[i];
                
                // CRITICAL FIX: Handle case where NO links could be created
                if (link_count == 0) {
                    // Output a dummy safe path (Spine 0, Link 0 on OXC 0) to avoid crash
                    // This will likely be invalid scoring-wise but prevents Runtime Error
                    routing_results[f_idx] = {0, 0, 0, 0, 0}; 
                } else {
                    LinkUse& link = links[i % link_count]; // Safe modulo
                    PortInfo infoA = get_port_info(link.oxc, link.u);
                    PortInfo infoB = get_port_info(link.oxc, link.v);
                    
                    if (flows[f_idx].gA == groups.first) {
                        routing_results[f_idx] = {infoA.spine, infoA.link, link.oxc, infoB.spine, infoB.link};
                    } else {
                        routing_results[f_idx] = {infoB.spine, infoB.link, link.oxc, infoA.spine, infoA.link};
                    }
                }
            }
        }

        for (int i = 0; i < Q; ++i) {
            cout << routing_results[i].sA << " " 
                 << routing_results[i].kA << " " 
                 << routing_results[i].m << " " 
                 << routing_results[i].sB << " " 
                 << routing_results[i].kB << "\n";
        }
    }
}

int main() {
    solve();
    return 0;
}
