/******************************************************************************

Longest subarray with sum K:

Given an array nums of size n and an integer k, find the length of the longest
sub-array that sums to k. If no such sub-array exists, return 0.


Example 1

Input: nums = [10, 5, 2, 7, 1, 9],  k=15

Output: 4

Explanation:

The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length
of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its
elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array
is 4.

Example 2

Input: nums = [-3, 2, 1], k=6

Output: 0

Explanation:

There is no sub-array in the array that sums to 6. Therefore, the output is 0.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestSubarray(vector<int> &nums, int k) {
    int longest_subarray_result = 0;

    for (int i = 0; i < nums.size(); i++) {
      int ind_subarray_sum = 0;
      int ind_subarray_len = 0;

      if (nums[i] <= k) {
        ind_subarray_sum = nums[i];
        ind_subarray_len = ind_subarray_len + 1;
        if (ind_subarray_sum == k) {
          longest_subarray_result =
              max(longest_subarray_result, ind_subarray_len);
        }
      }
      for (int j = i + 1; j < nums.size(); j++) {

        ind_subarray_sum = ind_subarray_sum + nums[j];
        ind_subarray_len = ind_subarray_len + 1;
        if (ind_subarray_sum == k) {
          longest_subarray_result =
              max(longest_subarray_result, ind_subarray_len);
          break;
        }
        if (ind_subarray_sum > k) {
          break;
        }
      }
    }
    return longest_subarray_result;
  }
};

int main() {
  cout << "Longest subarray with sum K" << endl;
  vector<int> nums = {10, 5, 2, 7, 1, 9};
  int k = 15;
  Solution sol;
  cout << sol.longestSubarray(nums, k);

  return 0;
}