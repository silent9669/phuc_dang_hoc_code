#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <cmath>
#include <doctest/doctest.h>

using namespace std;

class Solution {
public:
  double myPow(double x, int n) {
    double val = pow(x, abs((long long)n));
    return n < 0 ? 1.0 / val : val;
  }
};

TEST_CASE("myPow tests") {
  Solution sol;

  CHECK(sol.myPow(2.00000, 10) == 1024.00000);
  CHECK(sol.myPow(2.10000, 3) == 9.26100);
  CHECK(sol.myPow(2.00000, -2) == 0.25000);
}
