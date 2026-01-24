#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

class Solution {
public:
  int integerBreak(int n) {
    if (n == 2)
      return 1;
    else if (n == 3)
      return 2;
    else if (n % 3 == 0) {
      return pow(3, n / 3);
    } else if (n % 3 == 1) {
      return pow(3, n / 3 - 1) * 4;
    } else {
      return pow(3, n / 3) * 2;
    }
  }
};

TEST_CASE("integerBreak") {
  Solution sol;
  CHECK(sol.integerBreak(2) == 1);
  CHECK(sol.integerBreak(10) == 36);
}
