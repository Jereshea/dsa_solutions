/******************************************************************************

Given an array of integers nums and an integer target. Return the indices(0 -
indexed) of two elements in nums such that they add up to target.



Each input will have exactly one solution, and the same element cannot be used
twice.


Example 1

Input: nums = [1, 6, 2, 10, 3], target = 7

Output: [0, 1]

Explanation:

nums[0] + nums[1] = 1 + 6 = 7

Example 2

Input: nums = [1, 3, 5, -7, 6, -3], target = 0

Output: [1, 5]

Explanation:

nums[1] + nums[5] = 3 + (-3) = 0
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void arrange_arr(vector<int> &nums, int start, int mid, int end) {
    vector<int> left;
    vector<int> right;

    for (int i = start; i <= mid; i++) {
      left.push_back(nums[i]);
    }

    for (int i = mid + 1; i <= end; i++) {
      right.push_back(nums[i]);
    }

    // Sort
    int index_1 = 0;
    int index_2 = 0;
    int index = start;
    while (index_1 < left.size() && index_2 < right.size()) {
      if (left[index_1] < right[index_2]) {
        nums[index] = left[index_1];
        index = index + 1;
        index_1 = index_1 + 1;
      } else {
        nums[index] = right[index_2];
        index = index + 1;
        index_2 = index_2 + 1;
      }
    }

    while (index_1 < left.size()) {
      nums[index] = left[index_1];
      index = index + 1;
      index_1 = index_1 + 1;
    }

    while (index_2 < right.size()) {
      nums[index] = right[index_2];
      index = index + 1;
      index_2 = index_2 + 1;
    }
  }
  void sort_arr(vector<int> &nums, int start, int end) {
    if (start >= end) {
      return;
    }

    int mid = start + ((end - start) / 2);
    sort_arr(nums, start, mid);
    sort_arr(nums, mid + 1, end);
    arrange_arr(nums, start, mid, end);
  }
  vector<int> twoSum(vector<int> &nums, int target) {
    // store the index
    unordered_map<int, int> element_index_mapping;
    for (int i = 0; i < nums.size(); i++) {
      element_index_mapping[nums[i]] = i;
    }

    sort_arr(nums, 0, nums.size() - 1);
    for (auto &m : nums) {
      cout << m << " ";
    }

    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          result.push_back(nums[i]);
          result.push_back(nums[j]);
        }
        if (nums[i] + nums[j] > target) {
          break;
        }
      }
    }

    // Given each has only one solution
    result[0] = element_index_mapping[result[0]];
    result[1] = element_index_mapping[result[1]];
    return result;
  }
};

int main() {
  cout << "2 Sum" << endl;
  vector<int> nums = {1, 6, 2, 10, 3};
  int target = 7;
  Solution sol;
  vector<int> result = sol.twoSum(nums, target);
  cout << endl;
  for (auto &m : result) {
    cout << m << " ";
  }
  return 0;
}