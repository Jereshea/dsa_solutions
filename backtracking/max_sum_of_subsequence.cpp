/******************************************************************************

You are given an array nums consisting of integers. You are also given a 2D
array queries, where queries[i] = [posi, xi].

For query i, we first set nums[posi] equal to xi, then we calculate the answer
to query i which is the maximum sum of a subsequence of nums where no two
adjacent elements are selected.

Return the sum of the answers to all queries.

Since the final answer may be very large, return it modulo 109 + 7.

A subsequence is an array that can be derived from another array by deleting
some or no elements without changing the order of the remaining elements.



Example 1:

Input: nums = [3,5,9], queries = [[1,-2],[0,-3]]

Output: 21

Explanation:
After the 1st query, nums = [3,-2,9] and the maximum sum of a subsequence with
non-adjacent elements is 3 + 9 = 12. After the 2nd query, nums = [-3,-2,9] and
the maximum sum of a subsequence with non-adjacent elements is 9.

Example 2:

Input: nums = [0,-1], queries = [[0,-5]]

Output: 0

Explanation:
After the 1st query, nums = [-5,-1] and the maximum sum of a subsequence with
non-adjacent elements is 0 (choosing an empty subsequence).


*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void subsequence_arr(vector<int> &nums, int start, int end,
                       int &sub_sequence_sum,
                       vector<int> &sub_sequence_result) {
    if (start >= end) {
      int sum_arr = 0;
      for (int i = 0; i < sub_sequence_result.size(); i++) {
        sum_arr += sub_sequence_result[i];
      }
      sub_sequence_sum = max(sub_sequence_sum, sum_arr);
      return;
    }

    sub_sequence_result.push_back(nums[start]);
    subsequence_arr(nums, start + 2, nums.size(), sub_sequence_sum,
                    sub_sequence_result); // Here it is mentioned that no two
                                          // adjacent elemets should be
                                          // selected, so we increment by 2
    sub_sequence_result.pop_back();
    subsequence_arr(nums, start + 1, nums.size(), sub_sequence_sum,
                    sub_sequence_result);
  }
  int maximumSumSubsequence(vector<int> &nums, vector<vector<int>> &queries) {
    int result = 0;
    for (int i = 0; i < queries.size(); i++) {
      int index = queries[i][0];
      nums[index] = queries[i][1];

      // find subsequence of the updated array
      int sub_sequence_sum = INT_MIN;
      vector<int> sub_sequence_result;
      subsequence_arr(nums, 0, nums.size(), sub_sequence_sum,
                      sub_sequence_result);
      result += sub_sequence_sum;
    }
    return result;
  }
};
int main() {
  cout << "Maximum Sum of Subsequence With Non-adjacent Elements";
  vector<int> nums = {3, 5, 9};
  vector<vector<int>> queries = {{1, -2}, {0, -3}};
  Solution sol;
  cout << endl << endl << sol.maximumSumSubsequence(nums, queries);
  return 0;
}