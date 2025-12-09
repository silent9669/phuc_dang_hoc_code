#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Special case: if only 2 or fewer elements, beauty is 0
    if (n <= 2) {
        cout << 0 << endl;
        return 0;
    }

    int max_beauty = 0;  // This will store our answer

    // Try removing each element one by one
    for (int remove = 0; remove < n; remove++) {

        // After removing element at position 'remove',
        // we need to find the maximum difference in the new array
        int current_max = 0;

        // Check all pairs of consecutive elements in the new array
        for (int i = 0; i < n - 1; i++) {

            // Skip if we removed element i
            if (i == remove) {
                continue;
            }

            // Find the next element that wasn't removed
            int next = i + 1;
            if (next == remove) {
                next = i + 2;
            }

            // Make sure next is valid
            if (next >= n) {
                continue;
            }

            // Calculate the difference between a[next] and a[i]
            int diff = a[next] - a[i];

            // Update the maximum difference
            current_max = max(current_max, diff);
        }

        // Update the overall maximum beauty
        max_beauty = max(max_beauty, current_max);
    }

    cout << max_beauty << endl;

    return 0;
}

/*
=== EXAMPLE WALKTHROUGH: [2, 4, 5, 6] ===

Remove position 0 (value=2): Array becomes [4, 5, 6]
  - i=1: a[2]-a[1] = 5-4 = 1
  - i=2: a[3]-a[2] = 6-5 = 1
  - current_max = 1

Remove position 1 (value=4): Array becomes [2, 5, 6]
  - i=0: a[2]-a[0] = 5-2 = 3  ← (skip position 1)
  - i=2: a[3]-a[2] = 6-5 = 1
  - current_max = 3 ✓

Remove position 2 (value=5): Array becomes [2, 4, 6]
  - i=0: a[1]-a[0] = 4-2 = 2
  - i=1: a[3]-a[1] = 6-4 = 2  ← (skip position 2)
  - current_max = 2

Remove position 3 (value=6): Array becomes [2, 4, 5]
  - i=0: a[1]-a[0] = 4-2 = 2
  - i=1: a[2]-a[1] = 5-4 = 1
  - current_max = 2

ANSWER: max_beauty = 3
*/