#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Precompute prefix sums of absolute values for middle elements
    // prefAbs[i] stores sum of |a[0]...a[i-1]|
    // But logic requires sum from index 1 to k-2 (0-based indexing for array)
    // Let's make simpler arrays aligned with the formula.
    
    // prefAbs[i] will store sum of |a[j]| for 1 <= j < i (using 0-based index for a)
    // Corresponds to range a_2 ... a_i in 1-based problem statement
    vector<long long> prefAbs(n + 1, 0);
    for (int i = 1; i < n; ++i) {
        prefAbs[i] = prefAbs[i - 1] + abs(a[i]);
    }

    // Precompute suffix sums for standard values
    // suf[i] stores sum of a[j] for i <= j < n
    vector<long long> suf(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = suf[i + 1] + a[i];
    }

    long long max_val = -2e18; // Initialize with a very small number

    // Iterate through every possible survivor k (0-based index)
    for (int k = 0; k < n; ++k) {
        long long current_val = 0;

        if (k == 0) {
            // If a[0] (a_1) is the survivor
            // All others must be subtracted
            current_val = -suf[1];
        } else {
            // a[0] is Added
            current_val += a[0];
            
            // Middle elements a[1]...a[k-1] contribute |a[i]|
            // This is prefAbs[k] - prefAbs[1]
            // Since prefAbs[1] is |a[1]|? No, our definition:
            // prefAbs[k] stores sum of |a[j]| for j from 1 to k-1.
            // Wait, let's strictly follow the definition of prefAbs loop above:
            // prefAbs[1] = prefAbs[0] + |a[1]| = 0 + |a[1]|.
            // prefAbs[k] = |a[1]| + ... + |a[k]|.
            // We want sum from index 1 to k-1.
            // That is prefAbs[k-1] in the vector constructed above?
            // Loop: prefAbs[i] = prefAbs[i-1] + abs(a[i])
            // prefAbs[1] = abs(a[1])
            // prefAbs[2] = abs(a[1]) + abs(a[2])
            // We want indices 1 to k-1. That is exactly prefAbs[k-1].
            current_val += prefAbs[k - 1];
            
            // Suffix elements a[k+1]...a[n-1] are subtracted
            current_val -= suf[k + 1];
        }

        max_val = max(max_val, current_val);
    }

    cout << max_val << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
