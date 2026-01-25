/******************************************************************************

Longest subarray with sum K

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
    int result = 0;
    int sum = 0;
    // Maintain hasp_Map To store the cummulative_sum and its corresponding
    // index
    unordered_map<int, int> sum_index;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];

      if (sum_index.count(sum) == 0) {
        sum_index[sum] = i + 1;
      }

      if (sum == k) {
        result = max(result, i + 1);
      }
      // Index:   1 2 3 4
      // Element: 3 1 1 1
      // Check the hash_maps
      if (sum_index.count(sum - k)) {
        result = max(result, (i + 1) - sum_index[sum - k]);
      }
    }
    return result;
  }
};

int main() {
  cout << "Longest subarray with sum K" << endl;
  vector<int> nums = {10, 5, 2, 7, 1, 9};
  int k = 15;
  // vector<int> nums = {-3, 2, 1};
  // int k=6;
  Solution sol;
  cout << sol.longestSubarray(nums, k);

  return 0;
}