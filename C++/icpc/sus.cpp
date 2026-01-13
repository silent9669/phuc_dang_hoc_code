#include <bits/stdc++.h>
using namespace std;

void solve(){
  string r;
  cin >> r;
  
  int n = r.length();
    int ops = 0;

    // Safety check as per instructions
    for (char c : r) {
        assert(c == 's' || c == 'u');
    }

    // 1. Fix Boundaries
    // The string must start with 's'
    if (r[0] == 'u') {
        r[0] = 's';
        ops++;
    }
    // The string must end with 's'
    if (r[n - 1] == 'u') {
        r[n - 1] = 's';
        ops++;
    }

    // 2. Fix internal 'uu' occurrences
    // We iterate up to n-2 because we check r[i] and r[i+1]
    for (int i = 0; i < n - 1; i++) {
        if (r[i] == 'u' && r[i+1] == 'u') {
            r[i+1] = 's'; // Change the second 'u' to 's'
            ops++;
        }
    }

    cout << ops << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  while (n--){
    solve();
  }

  return 0;
}
