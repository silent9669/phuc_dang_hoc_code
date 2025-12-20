#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> odds;
    vector<long long> evens;
    
    // Read input and separate into odds and evens
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        if (a % 2 != 0) odds.push_back(a);
        else evens.push_back(a);
    }

    // Sort descending to access largest elements easily
    sort(odds.rbegin(), odds.rend());
    sort(evens.rbegin(), evens.rend());

    // Precompute prefix sums for evens to quickly calculate the sum of the top X evens
    int num_evens = evens.size();
    int num_odds = odds.size();
    vector<long long> prefix_evens(num_evens + 1, 0);
    for (int i = 0; i < num_evens; ++i) {
        prefix_evens[i + 1] = prefix_evens[i] + evens[i];
    }

    // Calculate answer for each k from 1 to n
    for (int k = 1; k <= n; ++k) {
        // If we have no odd coins, we can never make an odd sum, so score is always 0
        if (num_odds == 0) {
            cout << 0 << (k == n ? "" : " ");
            continue;
        }

        // We want to maximize the number of evens used.
        // We need at least 1 spot for an odd coin (the one that keeps the sum odd).
        // So max evens we can possibly fit is (k - 1).
        // Also bounded by how many evens we actually have.
        int take_evens = min(k - 1, num_evens);
        
        // The remaining spots must be filled by odds
        int take_odds = k - take_evens;

        // The number of odds used MUST be odd (1 keeper + pairs of wasters).
        // If take_odds is even, we swap one even for one odd.
        if (take_odds % 2 == 0) {
            take_evens--;
            take_odds++;
        }

        // Validity check:
        // 1. take_evens cannot be negative.
        // 2. We must have enough odd coins to satisfy take_odds.
        if (take_evens < 0 || take_odds > num_odds) {
            cout << 0 << (k == n ? "" : " ");
        } else {
            // Score = Sum of the chosen evens + the single largest odd
            // (The other take_odds-1 odds are wasted/cleared, so they don't add to score)
            long long current_score = prefix_evens[take_evens] + odds[0];
            cout << current_score << (k == n ? "" : " ");
        }
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
