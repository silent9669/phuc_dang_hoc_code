#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;

    vector<int> count_s(26, 0);
    vector<int> count_t(26, 0);

    for (char c : s) count_s[c - 'a']++;
    for (char c : t) count_t[c - 'a']++;

    // 1. Check if impossible
    for (int i = 0; i < 26; ++i) {
        if (count_t[i] < count_s[i]) {
            cout << "Impossible" << endl;
            return;
        }
    }

    // 2. Identify extra characters
    string extras = "";
    for (int i = 0; i < 26; ++i) {
        int diff = count_t[i] - count_s[i];
        for (int j = 0; j < diff; ++j) {
            extras += (char)('a' + i);
        }
    }
    // extras is naturally sorted because we iterated 0..25

    // 3. Precompute next distinct character for s
    // next_valid[i] stores the first character in s[i+1...] that is different from s[i]
    int n = s.length();
    vector<char> next_valid(n);
    char distinct = '{'; // '{' is the character after 'z' in ASCII, acts as infinity
    
    // Iterate backwards to fill next_valid info
    next_valid[n - 1] = distinct; 
    for (int i = n - 2; i >= 0; --i) {
        if (s[i] == s[i+1]) {
            next_valid[i] = next_valid[i+1];
        } else {
            next_valid[i] = s[i+1];
        }
    }

    // 4. Merge logic
    string result = "";
    int s_idx = 0;
    int e_idx = 0;

    while (s_idx < n) {
        char skel = s[s_idx];
        
        while (e_idx < extras.length()) {
            char extra = extras[e_idx];

            if (extra < skel) {
                // If extra is strictly smaller, take it now
                result += extra;
                e_idx++;
            } else if (extra == skel) {
                // If equal, check the lookahead logic
                char next_diff_char = next_valid[s_idx];
                
                if (skel < next_diff_char) {
                    // Current block is smaller than what comes after (e.g., 'a' then 'b')
                    // Put extras now to maximize small chars at the front
                    result += extra;
                    e_idx++;
                } else {
                    // Current block is larger than what comes after (e.g., 'b' then 'a')
                    // Hold extras to reach the smaller future char faster
                    break; 
                }
            } else {
                // extra > skel, must take skeleton char first
                break;
            }
        }
        
        // Take the required skeleton char
        result += skel;
        s_idx++;
    }

    // Append any remaining extras
    while (e_idx < extras.length()) {
        result += extras[e_idx++];
    }

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}