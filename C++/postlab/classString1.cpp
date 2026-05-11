#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  getline(cin, s);

  string longest = "";

  for (int i = 0; i < s.length(); i++) {

    int left = i, right = i;
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
      left--;
      right++;
    }
    string odd = s.substr(left + 1, right - left - 1);
    if (odd.length() > longest.length())
      longest = odd;

    left = i, right = i + 1;
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
      left--;
      right++;
    }

    string even = s.substr(left + 1, right - left - 1);
    if (even.length() > longest.length())
      longest = even;
  }

  cout << longest;

  return 0;
}
