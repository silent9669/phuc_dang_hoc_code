#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

using namespace std;

class Solution {
public:
  bool isPerfectSquare(int num) {
    if (num < 0)
      return false;
    if (num == 0 || num == 1)
      return true;
    for (long long i = 1; i * i <= num; i++) {
      if (i * i == num)
        return true;
      else if (i * i > num)
        return false;
      else
        continue;
    }
    return false;
  }
};

TEST_CASE("isPerfectSquare") {
  Solution sol;

  CHECK(sol.isPerfectSquare(16) == true);
  CHECK(sol.isPerfectSquare(14) == false);
  CHECK(sol.isPerfectSquare(1) == true);
  CHECK(sol.isPerfectSquare(0) == true);
  CHECK(sol.isPerfectSquare(25) == true);
}
