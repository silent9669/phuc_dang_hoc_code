#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const long long INF = 2e18; // Increased for safety

struct Edge {
    int u, v, id;
    long long w;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

// Disjoint Set Union (DSU) for MST
struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

// Global variables for LCA
int n, m;
vector<vector<pair<int, int>>> adj;
vector<int> tin, tout, depth;
vector<vector<int>> up;
int timer;
int LOG;

void dfs(int u, int p, int d) {
    tin[u] = ++timer;
    depth[u] = d;
    up[u][0] = p;
    for (int i = 1; i <= LOG; ++i) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (auto& edge : adj[u]) {
        int v = edge.first;
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
    tout[u] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int get_lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = LOG; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

// Check if the edge connecting p and c (where p is parent of c)
// lies on the simple path between u and v.
bool is_on_path(int p, int c, int u, int v) {
    int lca = get_lca(u, v);
    // The edge p-c is on the path u...v if it falls on the path u...lca or v...lca.
    // This means c must be an ancestor of u OR v,
    // AND lca must be an ancestor of p (strictly above c).

    if (!is_ancestor(lca, p)) return false;
    return is_ancestor(c, u) || is_ancestor(c, v);
}

void solve() {
    cin >> n >> m;
    vector<Edge> all_edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> all_edges[i].u >> all_edges[i].v >> all_edges[i].w;
        all_edges[i].id = i;
    }

    sort(all_edges.begin(), all_edges.end(), compareEdges);

    DSU dsu(n);
    vector<Edge> mst_edges;
    vector<Edge> other_edges;
    long long mst_weight = 0;

    adj.assign(n + 1, vector<pair<int, int>>());

    // Kruskal's to build MST
    for (const auto& edge : all_edges) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unite(edge.u, edge.v);
            mst_edges.push_back(edge);
            mst_weight += edge.w;
            // Build tree for LCA
            adj[edge.u].push_back({edge.v, -1});
            adj[edge.v].push_back({edge.u, -1});
        } else {
            other_edges.push_back(edge);
        }
    }

    // CASE 1: The graph is NOT connected (MST has fewer than n-1 edges)
    // Any subset of n-1 edges in a disconnected graph is a "non-tree".
    // We just take the n-1 cheapest edges globally.
    if (mst_edges.size() < n - 1) {
        long long sum = 0;
        for(int i = 0; i < n - 1; ++i) {
            sum += all_edges[i].w;
        }
        cout << sum << "\n";
        return;
    }

    // CASE 2: Graph is connected.
    // We have a full MST. We must swap edges to form a non-tree.
    if (other_edges.empty()) {
        cout << -1 << "\n";
        return;
    }

    // Precompute LCA structures
    timer = 0;
    tin.assign(n + 1, 0);
    tout.assign(n + 1, 0);
    depth.assign(n + 1, 0);
    LOG = 0;
    while ((1 << (LOG + 1)) <= n) LOG++;
    up.assign(n + 1, vector<int>(LOG + 1));

    // DFS from root 1 to build hierarchy
    dfs(1, 1, 0);

    // Store MST edges with parent-child orientation for O(1) checking
    struct OrientedEdge {
        int p, c;
        long long w;
    };
    vector<OrientedEdge> sorted_mst;
    sorted_mst.reserve(n-1);

    for (const auto& e : mst_edges) {
        if (depth[e.u] < depth[e.v]) sorted_mst.push_back({e.u, e.v, e.w});
        else sorted_mst.push_back({e.v, e.u, e.w});
    }

    // Sort MST edges Descending (Heaviest first) to maximize removal gain
    sort(sorted_mst.begin(), sorted_mst.end(), [](const OrientedEdge& a, const OrientedEdge& b) {
        return a.w > b.w;
    });

    long long current_ans = INF;

    // Pruning Strategy:
    // We want to minimize: MST_Weight + Add_Weight - Rem_Weight
    // other_edges is sorted ASC (Smallest Add first)
    // sorted_mst is sorted DESC (Largest Rem first)

    for (const auto& add : other_edges) {
        // Global Pruning:
        // Even if we remove the HEAVIEST edge in the entire MST,
        // if the cost is still >= current best, we can stop completely.
        // Because subsequent 'add' edges are heavier.
        if (mst_weight + add.w - sorted_mst[0].w >= current_ans) {
            break;
        }

        for (const auto& rem : sorted_mst) {
            // Local Pruning:
            // For this specific 'add', if removing the current 'rem'
            // results in a cost >= current best, stop the inner loop.
            // Subsequent 'rem' edges are lighter, so cost will increase.
            if (mst_weight + add.w - rem.w >= current_ans) {
                break;
            }

            // Validity Check:
            // We can only remove 'rem' if it is NOT on the cycle formed by 'add'.
            // If !is_on_path, the cycle persists, and graph becomes disconnected (valid non-tree).
            if (!is_on_path(rem.p, rem.c, add.u, add.v)) {
                current_ans = mst_weight + add.w - rem.w;
                // We found the best removal for this 'add' (because we iterate heavy to light).
                break;
            }
        }
    }

    if (current_ans == INF) cout << -1 << "\n";
    else cout << current_ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}