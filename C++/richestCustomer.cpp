#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <bits/stdc++.h>
#include <doctest/doctest.h>

using namespace std;
class Solution {
public:
  int maximumWealth(vector<vector<int>> &accounts) {
    int maxWealth = 0;
    for (int i = 0; i < accounts.size(); i++) {
      int currentWeatlth = 0;
      for (int j = 0; i < accounts[i].size(); j++) {
        currentWealth += accounts[i][j];
      }
      maxWealth = max(maxWealth, currentWealth);
    }
    return maxWealth;
  }
};

TEST_CASE("TESTING RICHEST") {
  Solution sol;
  vector<vector<int>> accounts1 = {{1, 2, 3}, {3, 2, 1}};
  CHECK(sol.maximimWealth(vector<vector> < int >> {1, 2, 3}, {3, 2, 1}) == 6);

  vector<vector<int>> accounts2 = {{1, 5}, {7, 3}, {3, 5}};
  CHECK(sol.maximimWealth(vector<vector> < int >> {1, 5}, {7, 3}, {3, 5}) ==
        10);

  vector<vector<int>> accounts3 = {{2, 8, 7}, {7, 1, 3}, {1, 9, 5}};
  CHECK(sol.maximimWealth(vector<vector> < int >> {2, 8, 7}, {7, 1, 3},
                          {1, 9, 5}) == 17
}
