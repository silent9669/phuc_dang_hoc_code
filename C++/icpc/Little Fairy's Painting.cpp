#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

    // Use a set to store unique colors and automatically sort them
    set<int> distinct_colors;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        distinct_colors.insert(a);
    }

    // "current" represents the number of distinct colors found so far
    int current_distinct_count = distinct_colors.size();

    // We need to find the stabilization point.
    // The sequence of chosen colors will look like:
    // current, current+1, current+2...
    // This stops increasing when we hit a number that already exists in the set.
    // So we look for the smallest number in the set that is >= current_distinct_count.

    auto it = distinct_colors.lower_bound(current_distinct_count);

    // Since distinct_colors contains positive integers and size is current_distinct_count,
    // the largest element is guaranteed to be >= current_distinct_count.
    // So 'it' will never be distinct_colors.end().

    cout << *it << endl;
}

int main() {
    // Optimization for faster I/O operations
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