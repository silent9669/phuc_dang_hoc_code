#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> solve(vector<int> p) {
    int n = p.size();
    int start = -1, end = -1;

    for (int i = 0; i < n; i++) {
      if (p[i] != n - i) {
        for (int j = i + 1; j < n; j++) {
          if (p[j] == n - i) {
            start = i;
            end = j;
            break;
          }
        }
        break;
      }
    }

    if (start != -1) {
      reverse(p.begin() + start, p.begin() + end + 1);
    }
    return p;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution sol;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }

    vector<int> result = sol.solve(p);
    for (int x : result) {
      cout << x << " ";
    }
    cout << "\n";
  }

  return 0;
}
