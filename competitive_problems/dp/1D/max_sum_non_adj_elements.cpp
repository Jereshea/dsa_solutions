/************

Maximum sum of non adjacent elements

Given an integer array nums of size n. Return the maximum sum possible using the
elements of nums such that no two elements taken are adjacent in nums.




Example 1

Input: nums = [1, 2, 4]

Output: 5

Explanation:

[1, 2, 4], the underlined elements are taken to get the maximum sum.

Example 2

Input: nums = [2, 1, 4, 9]

Output: 11

Explanation:

[2, 1, 4, 9], the underlined elements are taken to get the maximum sum.
****************/
#include <bits/stdc++.h>
using namespace std;

class Solution {

  /*
  // Recursion
  public:
      int nonAdjacent_rec(vector<int> &nums, int index){
          if(index>=nums.size()){
              return 0;
          }

          int include=nums[index]+nonAdjacent_rec(nums,index+2);
          int exclude=nonAdjacent_rec(nums,index+1);

          return max(include, exclude);
      }
      int nonAdjacent(vector<int>& nums) {
          return nonAdjacent_rec(nums, 0);
      }
  };
  */

  // DP
public:
  int nonAdjacent_rec(vector<int> &nums, int index, vector<int> &dp) {
    if (index >= nums.size()) {
      return 0;
    }

    if (dp[index] != INT_MIN) {
      return dp[index];
    }

    int include = nums[index] + nonAdjacent_rec(nums, index + 2, dp);
    int exclude = nonAdjacent_rec(nums, index + 1, dp);

    return dp[index] = max(include, exclude);
  }
  int nonAdjacent(vector<int> &nums) {
    vector<int> dp(nums.size() + 1, INT_MIN);
    return nonAdjacent_rec(nums, 0, dp);
  }
};

int main() {
  // your code goes here
  cout << "Maximum sum of non adjacent elements" << endl;
  vector<int> nums = {2, 1, 4, 9};
  Solution sol;
  cout << sol.nonAdjacent(nums);
}
