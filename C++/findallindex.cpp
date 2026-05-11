#include <iostream>

using namespace std;

void findAllIndex(string s1, string s2) {
  if (s2.length() == 0)
    return;

  char target = s2[0];
  bool found = 0;

  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] == target) {
      if (found)
        cout << " ";
      cout << i;
      found = true;
    }
  }
  if (!found)
    cout << -1;
}
