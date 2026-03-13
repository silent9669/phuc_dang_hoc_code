#include <algorithm>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <bits/stdc++.h>
#include <doctest/doctest.h>

using namespace std;
/*
class Solution {
public:
  string addBinary(string a, string b) {
    long long unsigned c = stoll(a, nullptr, 2);
    long long unsigned d = stoll(b, nullptr, 2);

    int sum = c + d;
    string result = "";
    if (sum == 0)
      return "0";
    while (sum > 0) {
      result += (sum & 1) ? "1" : "0";
      sum >>= 1;
    }

    reverse(result.begin(), result.end());
    return result;
  }
};
*/

class Solution {
public:
  string addBinary(string a, string b) {
    string result = "";
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
      int sum = carry;
      if (i >= 0) {
        sum += a[i--] - '0';
      }
      if (j >= 0) {
        sum += b[j--] - '0';
      }
      result += (sum % 2) + '0';
      carry = sum / 2;
    }

    reverse(result.begin(), result.end());
    return result;
  }
};

TEST_CASE("TEST") {
  Solution sol;

  CHECK(sol.addBinary("11", "1") == "100");
  CHECK(sol.addBinary("1010", "1011") == "10101");
  CHECK(sol.addBinary("10100000100100110110010000010101111011011001101110111111"
                      "111101000000101111001110001111100001101",
                      "11010100101110111000111110011000101010000110101110101000"
                      "0011011011001011101111001100000011011110011") ==
        "1101111011000100110001011101101000000111010001010110010000110110000011"
        "00011110011010010011000000000");
}
