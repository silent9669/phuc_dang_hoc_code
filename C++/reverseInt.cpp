#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    int rev = 0;
    string s = to_string(x);
    int start = 0;
    if (s[0] == '-') {
      start = 1;
    }
    for (int i = s.size() - 1; i >= start; i--) {
      int digit = s[i] - '0';
      if (rev > (INT_MAX - digit) / 10) {
        return 0; // overflow
      }
      rev = rev * 10 + digit;
    }
    if (start == 1) {
      rev = -rev;
    }
    return rev;
  }
};

TEST_CASE("reverse tests") {
  Solution sol;

  CHECK(sol.reverse(123) == 321);
  CHECK(sol.reverse(-123) == -321);
  CHECK(sol.reverse(120) == 21);
  CHECK(sol.reverse(0) == 0);
  CHECK(sol.reverse(1534236469) == 0); // Overflow case
}
