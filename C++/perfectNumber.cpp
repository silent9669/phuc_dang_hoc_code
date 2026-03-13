#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <bits/stdc++.h>
#include <doctest/doctest.h>
using namespace std;
class Solution {
public:
  bool checkPerfectNumber(int num) {
    if (num == 1)
      return false;
    int sum = 1;
    for (int i = 2; i <= sqrt(num); i++) {
      if (num % i == 0) {
        sum += i;
        sum += num / i;
      }
    }
    return sum == num;
  }
};

TEST_CASE("TEST") {
  Solution sol;

  CHECK(sol.checkPerfectNumber(28) == 1);
  CHECK(sol.checkPerfectNumber(7) == 0);
}
