#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

using namespace std;

class Solution {
public:
  int mySqrt(int x) {
    int val = sqrt(x);
    return val;
  }
};

TEST_CASE("SQRT TEST_CASE") {
  Solution sol;

  CHECK(sol.mySqrt(4) == 2);
  CHECK(sol.mySqrt(8) == 2);
}
