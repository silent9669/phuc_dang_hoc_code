#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <bits/stdc++.h>
#include <doctest/doctest.h>

using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    string result = "";
    string word = "";
    for (char c : s) {
      word.push_back(c);
      if (c == ' ') {
        word.pop_back();
        reverse(word.begin(), word.end());
        result += word;
        result += " ";
        word = "";
      }
    }

    if (!word.empty()) {
      reverse(word.begin(), word.end());
      result += word;
    }
    return result;
  }
};

TEST_CASE("TESTING") {
  Solution sol;

  CHECK(sol.reverseWords("Let's take LeetCode contest") ==
        "s'teL ekat edoCteeL tsetnoc");
  CHECK(sol.reverseWords("Mr Ding") == "rM gniD");
}
