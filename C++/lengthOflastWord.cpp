#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    int length = 0;
    int n = size(s);
    int i = n - 1;

    while (s[i] > 0 && s[i] == ' ') {
      i--;
    }

    while (i >= 0 && s[i] != ' ') {
      length++;
      i--;
    }

    return length;
  }
};

TEST_CASE("lengthOfLastWord") {
  Solution sol;

  CHECK(sol.lengthOfLastWord("Hello World") == 5);
  CHECK(sol.lengthOfLastWord("    fly me to the moon ") == 4);
  CHECK(sol.lengthOfLastWord("luffy is still joyboy") == 6);
}
