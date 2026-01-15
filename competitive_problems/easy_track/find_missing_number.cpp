/******************************************************************************

Find missing number

Given an integer array of size n containing distinct values in the range from 0
to n (inclusive), return the only number missing from the array within this
range.


Example 1

Input: nums = [0, 2, 3, 1, 4]

Output: 5

Explanation:

nums contains 0, 1, 2, 3, 4 thus leaving 5 as the only missing number in the
range [0, 5]

Example 2

Input: nums = [0, 1, 2, 4, 5, 6]

Output: 3

Explanation:

nums contains 0, 1, 2, 4, 5, 6 thus leaving 3 as the only missing number in the
range [0, 6]
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void merge_sort(vector<int> &nums, int start, int mid, int end) {
    vector<int> left;
    vector<int> right;

    for (int i = start; i <= mid; i++) {
      left.push_back(nums[i]);
    }
    for (int i = mid + 1; i <= end; i++) {
      right.push_back(nums[i]);
    }

    int left_index = 0;
    int right_index = 0;

    while (left_index < left.size() && right_index < right.size()) {
      if (left[left_index] < right[right_index]) {
        nums[start] = left[left_index];
        left_index = left_index + 1;
        start = start + 1;
      } else {
        nums[start] = right[right_index];
        right_index = right_index + 1;
        start = start + 1;
      }
    }

    while (left_index < left.size()) {
      nums[start] = left[left_index];
      left_index = left_index + 1;
      start = start + 1;
    }
    while (right_index < right.size()) {
      nums[start] = right[right_index];
      right_index = right_index + 1;
      start = start + 1;
    }
  }
  void sorting(vector<int> &nums, int start, int end) {
    if (start >= end) {
      return;
    }

    int mid = start + ((end - start) / 2);
    sorting(nums, start, mid);
    sorting(nums, mid + 1, end);
    merge_sort(nums, start, mid, end);
  }
  int missingNumber(vector<int> &nums) {
    sorting(nums, 0, nums.size() - 1);

    int val = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (val != nums[i]) {
        return val;
      }
      val = val + 1;
    }
    return val;
  }
};
int main() {
  cout << "Find missing number" << endl;
  vector<int> nums = {0, 2, 3, 1, 4};
  Solution sol;
  int ans = sol.missingNumber(nums);
  cout << ans << endl;

  // for(auto &m:nums){
  //     cout<<m<<" ";
  // }

  return 0;
}