#include <cstddef>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <bits/stdc++.h>
#include <doctest/doctest.h>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    size_t pos = haystack.find(needle);
    return (pos == string::npos) ? -1 : static_cast<int>(pos);
  }
};

TEST_CASE("TEST") {
  Solution sol;

  CHECK(sol.strStr("sadbutsad", "sad") == 0);
  CHECK(sol.strStr("leetcode", "leeto") == -1);
}
