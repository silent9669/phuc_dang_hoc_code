#include <string>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <bits/stdc++.h>
#include <doctest/doctest.h>

using namespace std;

class Solution {
public:
  string addStrings(string num1, string num2) { string result = ""; }
};

TEST_CASE("TEST") {
  Solution sol;

  CHECK(sol.addStrings("11", "123") == "134");
  CHECK(sol.addStrings("456", "77") == "533");
  CHECK(sol.addStrings("0", "0") == "0");
}
