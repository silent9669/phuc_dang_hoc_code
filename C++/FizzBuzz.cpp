#include <string>
#include <vector>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

using namespace std;

class Solution {
public:
  vector<string> fizzBuzz(int n) {
    vector<string> result;
    for (int i = 1; i <= n; i++) {
      bool divisible3 = i % 3 == 0;
      bool divisible5 = i % 5 == 0;

      if (divisible3 && divisible5) {
        result.push_back("FizzBuzz");
      } else if (divisible3) {
        result.push_back("Fizz");
      } else if (divisible5) {
        result.push_back("Buzz");
      }

      else {
        result.push_back(to_string(i));
      }
    }

    return result;
  }
};

TEST_CASE("Test basic cases") {
  Solution sol;

  CHECK(sol.fizzBuzz(1) == vector<string>{"1"});
  CHECK(sol.fizzBuzz(2) == vector<string>{"1", "2"});
  CHECK(sol.fizzBuzz(3) == vector<string>{"1", "2", "Fizz"});
  CHECK(sol.fizzBuzz(5) == vector<string>{"1", "2", "Fizz", "4", "Buzz"});
  CHECK(sol.fizzBuzz(15) ==
        vector<string>{"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz",
                       "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"});
}

TEST_CASE("Test multiples of 3") {
  Solution sol;

  auto result = sol.fizzBuzz(9);
  CHECK(result[2] == "Fizz");
  CHECK(result[5] == "Fizz");
  CHECK(result[8] == "Fizz");
}

TEST_CASE("Test multiples of 5") {
  Solution sol;

  auto result = sol.fizzBuzz(10);
  CHECK(result[4] == "Buzz");
  CHECK(result[9] == "Buzz");
}

TEST_CASE("Test multiples of both 3 and 5") {
  Solution sol;

  auto result = sol.fizzBuzz(30);
  CHECK(result[14] == "FizzBuzz");
  CHECK(result[29] == "FizzBuzz");
}

TEST_CASE("Test regular numbers") {
  Solution sol;

  auto result = sol.fizzBuzz(10);
  CHECK(result[0] == "1");
  CHECK(result[1] == "2");
  CHECK(result[2] == "Fizz");
  CHECK(result[3] == "4");
  CHECK(result[6] == "7");
}

TEST_CASE("Test edge cases") {
  Solution sol;

  auto result = sol.fizzBuzz(100);
  CHECK(result[0] == "1");
  CHECK(result[29] == "FizzBuzz");
  CHECK(result[44] == "FizzBuzz");
  CHECK(result[59] == "FizzBuzz");
  CHECK(result[74] == "FizzBuzz");
  CHECK(result[89] == "FizzBuzz");
}
