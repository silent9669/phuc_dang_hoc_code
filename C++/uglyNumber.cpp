#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

using namespace std;

class Solution {
public:
  bool isUgly(int n) {
    if (n <= 0)
      return false;
    if (n == 1)
      return true;
    if (n % 2 == 0) {
      return isUgly(n / 2);
    } else if (n % 3 == 0) {
      return isUgly(n / 3);
    } else if (n % 5 == 0) {
      return isUgly(n / 5);
    }
    return false;
  }
};

TEST_CASE("isUgly") {
  Solution sol;

  CHECK(sol.isUgly(6) == true);
  CHECK(sol.isUgly(8) == true);
  CHECK(sol.isUgly(14) == false);
  CHECK(sol.isUgly(1) == true);
  CHECK(sol.isUgly(0) == false);
}
