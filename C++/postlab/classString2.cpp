#include <iostream>
#include <string>

using namespace std;

int longestNonRepeatSubString(string s) {
  bool seen[256] = {false};
  int left = 0, maxlength = 0;
  for (int right = 0; right < s.length(); right++) {
    while (seen[s[right]]) {
      seen[s[left]] = false;
      left++;
    }

    seen[s[right]] = true;
    if (right - left + 1 > maxlength) {
      maxlength = right - left + 1;
    }
  }
  return maxlength;
}

int main() {
  string s;
  cin >> s;
  cout << longestNonRepeatSubString(s);
  return 0;
}
