#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <algorithm>
#include <doctest/doctest.h>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string toHex(int num) {
    // Handle the special case of 0
    if (num == 0)
      return "0";

    // Hexadecimal character mapping
    const string hexChars = "0123456789abcdef";
    string result = "";

    // Process up to 8 hex digits (32 bits / 4 bits per hex digit)
    while (num != 0 && result.length() < 8) {
      // Extract the last 4 bits using bitwise AND with 15 (binary 1111)
      int lastFourBits = num & 0xF; // 0xF is 15 in hex

      // Map the 4 bits to the corresponding hex character
      result.push_back(hexChars[lastFourBits]);

      // Logical right shift by 4 bits
      // For negative numbers, we need to use unsigned arithmetic to get the
      // correct bits
      num = static_cast<unsigned int>(num) >> 4;
    }

    // Reverse the string because we processed digits from least significant to
    // most
    reverse(result.begin(), result.end());
    return result;
  }
};

TEST_CASE("Testing toHex function") {
  Solution sol;

  CHECK(sol.toHex(26) == "1a");
  CHECK(sol.toHex(-1) == "ffffffff");
  CHECK(sol.toHex(0) == "0");
  CHECK(sol.toHex(255) == "ff");
  CHECK(sol.toHex(16) == "10");
  CHECK(sol.toHex(-255) == "ffffff01");
}
