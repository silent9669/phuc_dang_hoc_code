#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v;
};

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    // Use 1-based indexing for convenience
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v;
    }

    // Sort edges based on the value of the destination node a[v].
    // This ensures we process paths in increasing order of their values,
    // satisfying the topological order required for the DP because a[next] > a[curr].
    sort(edges.begin(), edges.end(), [&](const Edge& x, const Edge& y) {
        return a[x.v] < a[y.v];
    });

    // incoming_stats[v][val] stores the sum of valid paths ending at vertex 'v'
    // such that the vertex immediately preceding 'v' in the path had value 'val'.
    // Map key: Value of the previous node.
    // Map value: Count of paths.
    vector<map<long long, long long>> incoming_stats(n + 1);

    long long total_paths = 0;
    const long long MOD = 998244353;

    for (const auto& e : edges) {
        int u = e.u;
        int v = e.v;

        // Base case: The edge (u, v) itself is a valid sequence of length 2.
        long long current_edge_paths = 1;

        // Calculate the required value of the node before u:
        // If u->v is an extension, then a[v] = a[prev] + a[u] => a[prev] = a[v] - a[u].
        long long required_prev_val = a[v] - a[u];

        // We can only extend if the required previous value is a valid natural number (>= 1).
        if (required_prev_val >= 1) {
            // Check if vertex 'u' has any incoming paths coming from a node with the required value.
            if (incoming_stats[u].count(required_prev_val)) {
                current_edge_paths = (current_edge_paths + incoming_stats[u][required_prev_val]) % MOD;
            }
        }

        // Add the counts calculated for this edge to the global total.
        total_paths = (total_paths + current_edge_paths) % MOD;

        // Update the stats for vertex 'v'.
        // Any path ending at 'v' through this edge 'u->v' now has 'u' (value a[u]) as the predecessor.
        incoming_stats[v][a[u]] = (incoming_stats[v][a[u]] + current_edge_paths) % MOD;
    }

    cout << total_paths << "\n";
}

int main() {
    // Fast I/O
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
