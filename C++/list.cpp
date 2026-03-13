#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream fi("list.inp");
  ofstream fo("list.out");

  string s;
  if (!(fi >> s))
    return 0;

  int n = s.length();
  bool ok = false;

  for (int i = 0; i < n; i++) {
    for (char c = 'a'; c < s[i]; c++) {
      int p = -1;
      for (int j = n - 1; j > i; j--) {
        if (s[j] == c) {
          p = j;
          break;
        }
      }
      if (p != -1) {
        char t = s[i];
        s[i] = s[p];
        s[p] = t;
        ok = true;
        break;
      }
    }
    if (ok)
      break;
  }

  fo << s;

  fi.close();
  fo.close();
  return 0;
}
