#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

using namespace std;

class Solution {
public:
  int numSquares(int n) {}
};

TEST_CASE("numSquares") {
  Solution sol;

  CHECK(sol.numSquares(12) == 3); // 4 + 4 + 4
  CHECK(sol.numSquares(13) == 2); // 4 + 9
  CHECK(sol.numSquares(1) == 1);  // 1
  CHECK(sol.numSquares(2) == 2);  // 1 + 1
  CHECK(sol.numSquares(3) == 3);  // 1 + 1 + 1
}
