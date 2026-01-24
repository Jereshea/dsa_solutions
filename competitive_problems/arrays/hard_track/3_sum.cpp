/******************************************************************************

3 Sum

Given an integer array nums. Return all triplets such that:



i != j, i != k, and j != k


nums[i] + nums[j] + nums[k] == 0.


Notice that the solution set must not contain duplicate triplets. One element
can be a part of multiple triplets. The output and the triplets can be returned
in any order.


Example 1

Input: nums = [2, -2, 0, 3, -3, 5]

Output: [[-2, 0, 2], [-3, -2, 5], [-3, 0, 3]]

Explanation:

nums[1] + nums[2] + nums[0] = 0

nums[4] + nums[1] + nums[5] = 0

nums[4] + nums[2] + nums[3] = 0

Example 2

Input: nums = [2, -1, -1, 3, -1]

Output: [[-1, -1, 2]]

Explanation:

nums[1] + nums[2] + nums[0] = 0

Note that we have used two -1s as they are separate elements with different
indexes

But we have not used the -1 at index 4 as that would create a duplicate triplet
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void threeSum_subsequence(vector<int> &nums, int cnt_nums,
                            vector<int> &subsequence, int index,
                            vector<vector<int>> &result, int sum) {
    if (cnt_nums == 3) {
      if (sum == 0) {
        sort(subsequence.begin(), subsequence.end());
        result.push_back(subsequence);
      }
      return;
    }
    if (cnt_nums > 3) {
      return;
    }

    if (index >= nums.size()) {
      return;
    }

    subsequence.push_back(nums[index]);
    // include
    threeSum_subsequence(nums, cnt_nums + 1, subsequence, index + 1, result,
                         sum + nums[index]);
    subsequence.pop_back();
    // exclude
    threeSum_subsequence(nums, cnt_nums, subsequence, index + 1, result, sum);
  }
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<int> subsequence;
    vector<vector<int>> result;
    threeSum_subsequence(nums, 0, subsequence, 0, result, 0);
    return result;
  }
};

int main() {
  cout << "3 Sum" << endl;
  // vector<int> nums = {2, -1, -1, 3, -1};
  vector<int> nums = {2, -2, 0, 3, -3, 5};
  Solution sol;
  vector<vector<int>> result = sol.threeSum(nums);

  for (auto &m : result) {
    for (auto &x : m) {
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}