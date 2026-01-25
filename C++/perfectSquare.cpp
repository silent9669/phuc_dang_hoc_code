#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

using namespace std;

class Solution {
public:
  int numSquares(int n) {
    // check if is the n^3 number

    if (isPerfectSquare(n)) {
      return 1;
    }

    if (isFourSquare(n)) {
      return 4;
    }

    for (int i = 1; i * i <= n; ++i) {
      if (isPerfectSquare(n - i * i)) {
        return 2;
      }
    }

    return 3;
  }

private:
  bool isPerfectSquare(int n) {
    for (int i = 1; i * i <= n; ++i) {
      if (i * i == n) {
        return true;
      }
    }
    return false;
  }

  bool isFourSquare(int n) {
    while (n % 4 == 0) {
      n /= 4;
    }
    return n % 8 == 7;
  }
};

  TEST_CASE("numSquares") {
    Solution sol;

    CHECK(sol.numSquares(12) == 3); // 4 + 4 + 4
    CHECK(sol.numSquares(13) == 2); // 4 + 9
    CHECK(sol.numSquares(1) == 1);  // 1
    CHECK(sol.numSquares(2) == 2);  // 1 + 1
    CHECK(sol.numSquares(3) == 3);  // 1 + 1 + 1
  }
