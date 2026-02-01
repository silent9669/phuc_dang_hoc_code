#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <bits/stdc++.h>
#include <doctest/doctest.h>

using namespace std;

class Solution {
public:
  int numberOfSteps(int n) {
    int count = 0;

    while (n > 0) {
      if (n & 1) {
        n--;
        count++;
      } else {
        n /= 2;
        count++;
      }
    }

    return count;
  }
};

TEST_CASE("TEST") {
  Solution sol;

  CHECK(sol.numberOfSteps(14) == 6);
  CHECK(sol.numberOfSteps(8) == 4);
  CHECK(sol.numberOfSteps(123) == 12);
}
