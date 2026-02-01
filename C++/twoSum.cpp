#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    int sum = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        sum = nums[i] + nums[j];
        if (sum == target) {
          return {i, j};
        }
      }
    }
    return {};
  }
};

TEST_CASE("Test twoSum") {
  Solution sol;

  vector<int> nums1 = {2, 7, 11, 15};
  int target1 = 9;
  vector<int> result1 = sol.twoSum(nums1, target1);
  CHECK(result1 == vector<int>{0, 1});

  vector<int> nums2 = {3, 2, 4};
  int target2 = 6;
  vector<int> result2 = sol.twoSum(nums2, target2);
  CHECK(result2 == vector<int>{1, 2});

  vector<int> nums3 = {3, 3};
  int target3 = 6;
  vector<int> result3 = sol.twoSum(nums3, target3);
  CHECK(result3 == vector<int>{0, 1});
}
