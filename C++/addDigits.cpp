#include <string>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

using namespace std;

class Solution {
public:
  int addDigits(int num) {
    while (num >= 10) {
      int sum = 0;
      while (num > 0) {
        sum += num % 10;
        num /= 10;
      }
      num = sum;
    }

    return num;
  }
};

TEST_CASE("addDigits") {
  Solution sol;

  CHECK(sol.addDigits(38) == 2);
  CHECK(sol.addDigits(0) == 0);
  CHECK(sol.addDigits(2) == 2);
  CHECK(sol.addDigits(11) == 2);
  CHECK(sol.addDigits(1) == 1);
}
