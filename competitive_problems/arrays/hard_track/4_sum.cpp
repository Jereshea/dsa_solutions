/******************************************************************************

4 Sum

Given an integer array nums and an integer target. Return all quadruplets
[nums[a], nums[b], nums[c], nums[d]] such that:



a, b, c, d are all distinct valid indices of nums.


nums[a] + nums[b] + nums[c] + nums[d] == target.


Notice that the solution set must not contain duplicate quadruplets. One element
can be a part of multiple quadruplets. The output and the quadruplets can be
returned in any order.


Example 1

Input: nums = [1, -2, 3, 5, 7, 9], target = 7

Output: [[-2, 1, 3, 5]]

Explanation:

nums[1] + nums[0] + nums[2] + nums[3] = 7

Example 2

Input: nums = [7, -7, 1, 2, 14, 3], target = 9

Output: []

Explanation:

No quadruplets are present which add upto 9
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {

    sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    for (int i = 0; i < nums.size(); i++) {

      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      for (int j = i + 1; j < nums.size(); j++) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }

        int left = j + 1;
        int right = nums.size() - 1;
        while (left < right) {
          int sum = nums[i] + nums[j] + nums[left] + nums[right];

          if (sum < target) {
            left++;
          } else if (sum > target) {
            right--;
          } else {
            result.push_back({nums[i], nums[j], nums[left], nums[right]});

            left++;
            while (left < right && nums[left] == nums[left + 1]) {
              left++;
            }

            right--;
            while (left < right && nums[right] == nums[right - 1]) {
              right--;
            }
          }
        }
      }
    }
    return result;
  }
};

int main() {
  cout << "4 Sum" << endl;
  // vector<int> nums = {2, -1, -1, 3, -1};
  vector<int> nums = {1, -2, 3, 5, 7, 9};
  int target = 7;
  Solution sol;
  vector<vector<int>> result = sol.fourSum(nums, target);

  for (auto &m : result) {
    for (auto &x : m) {
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}