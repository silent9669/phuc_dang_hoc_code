#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    static const string thousands[] = {"", "M", "MM", "MMM"};
    static const string hundreds[] = {"",  "C",  "CC",  "CCC",  "CD",
                                      "D", "DC", "DCC", "DCCC", "CM"};
    static const string tens[] = {"",  "X",  "XX",  "XXX",  "XL",
                                  "L", "LX", "LXX", "LXXX", "XC"};
    static const string ones[] = {"",  "I",  "II",  "III",  "IV",
                                  "V", "VI", "VII", "VIII", "IX"};

    return thousands[num / 1000] + hundreds[(num % 1000) / 100] +
           tens[(num % 100) / 10] + ones[num % 10];
  }
};

TEST_CASE("intToRoman tests") {
  Solution sol;

  CHECK(sol.intToRoman(3) == "III");
  CHECK(sol.intToRoman(4) == "IV");
  CHECK(sol.intToRoman(9) == "IX");
  CHECK(sol.intToRoman(58) == "LVIII");
  CHECK(sol.intToRoman(1994) == "MCMXCIV");
}
