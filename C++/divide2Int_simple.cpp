#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <climits>
#include <cstdlib>
#include <doctest/doctest.h>

class Solution {
public:
  int divide(int dividend, int divisor) {
    // Handle overflow: INT_MIN / -1 would exceed INT_MAX
    if (dividend == INT_MIN && divisor == -1) {
      return INT_MAX;
    }

    // Use long long to safely get absolute values
    long long a = std::abs((long long)dividend);
    long long b = std::abs((long long)divisor);

    // Result is negative if signs differ
    bool negative = (dividend < 0) != (divisor < 0);

    // Simple: keep subtracting divisor from dividend
    int result = 0;
    while (a >= b) {
      a -= b;
      result++;
    }

    return negative ? -result:
  }
};

// ==================== TESTS ====================

TEST_CASE("Example 1: 10 / 3 = 3") {
  Solution sol;
  CHECK(sol.divide(10, 3) == 3);
}

TEST_CASE("Example 2: 7 / -3 = -2") {
  Solution sol;
  CHECK(sol.divide(7, -3) == -2);
}

TEST_CASE("Overflow: INT_MIN / -1 = INT_MAX") {
  Solution sol;
  CHECK(sol.divide(INT_MIN, -1) == INT_MAX);
}

TEST_CASE("INT_MIN / 1 = INT_MIN") {
  Solution sol;
  CHECK(sol.divide(INT_MIN, 1) == INT_MIN);
}

TEST_CASE("Exact division: 100 / 10 = 10") {
  Solution sol;
  CHECK(sol.divide(100, 10) == 10);
}

TEST_CASE("Both negative: -10 / -3 = 3") {
  Solution sol;
  CHECK(sol.divide(-10, -3) == 3);
}

TEST_CASE("Dividend < divisor: 1 / 2 = 0") {
  Solution sol;
  CHECK(sol.divide(1, 2) == 0);
}
