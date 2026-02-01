#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <bits/stdc++.h>
#include <doctest/doctest.h>

using namespace std;

class Solution {
public:
  int fib(int n) {
    if (n <= 2) {
      return 1;
    }
    int a = 1, b = 1, c;
    for (int i = 3; i <= n; i++) {
      c = a + b;
      a = b;
      b = c;
    }
    return b;
  }
};

int solve() {
  Solution sol;
  int n;
  cin >> n;

  cout << sol.fib(n) << endl;
  return 0;
}

TEST_CASE("Testing fib function") {
  Solution sol;

  CHECK(sol.fib(1) == 1);
  CHECK(sol.fib(2) == 1);
  CHECK(sol.fib(3) == 2);
  CHECK(sol.fib(4) == 3);
  CHECK(sol.fib(5) == 5);
  CHECK(sol.fib(6) == 8);
  CHECK(sol.fib(7) == 13);
  CHECK(sol.fib(8) == 21);
  CHECK(sol.fib(9) == 34);
  CHECK(sol.fib(10) == 55);
}
