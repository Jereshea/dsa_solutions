/******************************************************************************

Given an integer array nums, find the subarray with the largest sum and return
the sum of the elements present in that subarray.


Kadane's Algorithm:

A subarray is a contiguous non-empty sequence of elements within an array.


Example 1

Input: nums = [2, 3, 5, -2, 7, -4]

Output: 15

Explanation:

The subarray from index 0 to index 4 has the largest sum = 15

Example 2

Input: nums = [-2, -3, -7, -2, -10, -4]

Output: -2

Explanation:

The element on index 0 or index 3 make up the largest sum when taken as a
subarray
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int result_sum = nums[0];
    int curr_sum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      curr_sum = max(nums[i], curr_sum + nums[i]);
      result_sum = max(result_sum, curr_sum);
    }
    return result_sum;
  }
};

int main() {
  cout << "Kadane's Algorithm" << endl;
  vector<int> nums = {-2, -3, -7, -2, -10, -4};
  Solution sol;
  cout << sol.maxSubArray(nums);

  return 0;
}