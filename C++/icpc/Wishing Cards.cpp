/**
 * Problem: Wishing Cards
 * Status: Optimized for TLE and MLE
 *
 * Optimizations:
 * 1. Time: O(1) Lookups using a Precomputed Next Table.
 * 2. Memory: Global buffers to prevent allocation churn.
 * - nxt_buffer: Flattened 1D array reused across test cases.
 * - dp table: Static 2D array of vectors, cleared but not destroyed.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --- global constants ---
const int MAX_K = 365; // Slightly larger than 360 for safety

// --- Data Structures ---

struct State {
    int index;
    int penalty;
};

// GLOBAL BUFFERS
// 1. Next Occurrence Table (Flattened)
//    Size: Max N * Max K approx 3.6 * 10^7 ints (~144 MB). Fits in 256MB.
//    We reserve this once to avoid reallocation.
vector<int> nxt_buffer;

// 2. DP Table
//    Static array to avoid the overhead of creating vector-of-vectors every test case.
vector<State> dp[MAX_K][MAX_K];

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // --- 1. Precompute Next Table (O(NK)) ---

    // Resize buffer if current test case needs more space than currently allocated
    long long required_size = (long long)(n + 1) * (k + 1);
    if (nxt_buffer.size() < required_size) {
        nxt_buffer.resize(required_size);
    }

    // We use raw pointers for fastest access and to treat the 1D buffer as 2D
    int* nxt_ptr = nxt_buffer.data();
    int row_stride = k + 1; // Width of one row in the flattened table

    // last_match[v] stores the index of the nearest friend >= current_index
    // who can carry at least 'v' cards.
    vector<int> last_match(k + 1, -1);

    // Fill table backwards from N-1 down to 0
    for (int i = n - 1; i >= 0; --i) {
        int val = a[i];
        int limit = (val < k) ? val : k; // min(val, k)

        // This friend 'i' can satisfy any requirement v <= a[i]
        // So they become the new "nearest match" for those values.
        for (int v = 1; v <= limit; ++v) {
            last_match[v] = i;
        }

        // Copy current state of last_match to the global buffer row for index i
        // nxt[i][v] = last_match[v]
        int row_start = i * row_stride;
        for (int v = 1; v <= k; ++v) {
            nxt_ptr[row_start + v] = last_match[v];
        }
    }

    // --- 2. Dynamic Programming ---

    // Clean only the parts of the DP table we are about to use.
    // .clear() keeps the capacity, so no deallocation happens.
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j].clear();
        }
    }

    // Initial state: Cost 0, Last Value 0, Index -1, Penalty 0
    dp[0][0].push_back({-1, 0});

    long long max_happiness = 0;

    for (int w = 0; w <= k; ++w) {
        // Optimization: last_val 'v' cannot be greater than current cost 'w'
        for (int v = 0; v <= w; ++v) {
            if (dp[w][v].empty()) continue;

            auto& states = dp[w][v];

            // --- Pruning (Pareto Frontier) ---
            // Keep states with Small Index and Small Penalty.
            // If State A has larger index AND larger penalty than State B, State A is useless.
            if (states.size() > 1) {
                // Sort by index ascending
                sort(states.begin(), states.end(), [](const State& lhs, const State& rhs) {
                    return lhs.index < rhs.index;
                });

                int write_idx = 0;
                int min_penalty = 2e9; // Infinity

                for (const auto& s : states) {
                    // Since indices are increasing, we only keep this state if it offers
                    // a strictly better (lower) penalty than what we've seen so far.
                    if (s.penalty < min_penalty) {
                        states[write_idx++] = s;
                        min_penalty = s.penalty;
                    }
                }
                states.resize(write_idx);
            }

            // --- Transitions ---
            int max_next_v = k - w; // Remaining capacity

            for (int next_v = v + 1; next_v <= max_next_v; ++next_v) {
                int next_w = w + next_v;

                for (const auto& s : states) {
                    // Start searching strictly after the current friend
                    int search_start = s.index + 1;
                    if (search_start >= n) continue;

                    // O(1) Lookup in flattened table
                    int idx = nxt_ptr[search_start * row_stride + next_v];

                    if (idx != -1) {
                        int penalty_increase = idx * (next_v - v);
                        int new_penalty = s.penalty + penalty_increase;

                        // Calculate potential total happiness
                        long long current_H = (long long)next_v * n - new_penalty;
                        if (current_H > max_happiness) {
                            max_happiness = current_H;
                        }

                        dp[next_w][next_v].push_back({idx, new_penalty});
                    } else {
                        // Optimization:
                        // 'states' are sorted by index. 's' has the smallest index.
                        // If we can't find a friend for 's', we definitely can't find
                        // one for any subsequent state (which starts even later).
                        break;
                    }
                }
            }
        }
    }

    cout << max_happiness << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Reserve memory to prevent initial reallocation resizing lag
    // 5 * 10^5 * 20 (avg K) is a safe heuristic start
    nxt_buffer.reserve(10000000);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}