#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <bits/stdc++.h>
#include <doctest/doctest.h>

using namespace std;

class Solution {
public:
  vector<int> runningSum(vector<int> &nums) {
    vector<int> result;
    int sum = 0;
    for (int i : nums) {
      sum += i;
      result.push_back(sum);
    }
    return result;
  }
};

int solve() {
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }

  Solution sol;
  vector<int> result = sol.runningSum(nums);
  for (int val : result) {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}

TEST_CASE("Testing runningSum function") {
  Solution sol;

  SUBCASE("Test Case 1") {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> expected = {1, 3, 6, 10};
    CHECK(sol.runningSum(nums) == expected);
  }

  SUBCASE("Test Case 2") {
    vector<int> nums = {1, 1, 1, 1, 1};
    vector<int> expected = {1, 2, 3, 4, 5};
    CHECK(sol.runningSum(nums) == expected);
  }

  SUBCASE("Test Case 3") {
    vector<int> nums = {3, 1, 2, 10, 1};
    vector<int> expected = {3, 4, 6, 16, 17};
    CHECK(sol.runningSum(nums) == expected);
  }
}
