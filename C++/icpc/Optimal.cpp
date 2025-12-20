#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // This is the number of test cases (t)
    cin >> n;

    // Loop through each test case
    for (size_t i = 0; i < n; i++) {
        
        int m; // This is the length of the binary string
        cin >> m;

        string s;
        cin >> s;

        // --- Logic starts here ---

        // Optimization: If there are no zeros, cost is 0
        bool has_zero = false;
        for(char c : s){
            if(c == '0') {
                has_zero = true;
                break;
            }
        }

        if(!has_zero){
            cout << 0 << "\n";
            continue;
        }

        // To handle the cyclic nature (zeros wrapping from end to start),
        // we simply concatenate the string to itself.
        // e.g., "0110" becomes "01100110". The wrapped zeros "0...0" become "00".
        string s2 = s + s;

        int max_zeros = 0;
        int current_zeros = 0;

        // Iterate through the doubled string to find the longest chain of '0's
        for (char c : s2) {
            if (c == '0') {
                current_zeros++;
            } else {
                max_zeros = max(max_zeros, current_zeros);
                current_zeros = 0;
            }
        }
        // Final check in case the string ends with zeros
        max_zeros = max(max_zeros, current_zeros);

        // The answer is simply the size of the biggest gap
        cout << max_zeros << "\n";
    }

    return 0;
}
