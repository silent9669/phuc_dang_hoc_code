#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <bits/stdc++.h>
#include <doctest/doctest.h>

using namespace std;
class Solution {
public:
  char findTheDifference(string s, string t) {
    int sCount = 0;
    int tCount = 0;

    for (char c : s) {
      sCount += c;
    }

    for (char c : t) {
      tCount += c;
    }

    if (tCount > sCount) {
      return (char)(tCount - sCount);
    }

    else if (sCount > tCount) {
      return (char)(sCount - tCount);
    }

    return ' ';
  }
};

TEST_CASE("findTheDifference") {
  Solution sol;

  CHECK(sol.findTheDifference("abcd", "abcde") == 'e');
  CHECK(sol.findTheDifference("", "y") == 'y');
}
