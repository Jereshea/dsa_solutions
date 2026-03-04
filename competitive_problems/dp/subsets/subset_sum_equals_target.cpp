/******************************************************************************

Subset sum equals to target

Given an array arr of n integers and an integer target, determine if there is a
subset of the given array with a sum equal to the given target.


Example 1

Input: arr = [1, 2, 7, 3], target = 6

Output: True

Explanation: There is a subset (1, 2, 3) with sum 6.

Example 2

Input: arr = [2, 3, 5], target = 6

Output: False

Explanation: There is no subset with sum 6.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
// Recursion
class Solution{
public:
    bool isSubsetSum_rec(vector<int> &arr, int target, int index,int sum){
        if(sum == target){
            return true;
        }

        if(index >= arr.size()){
            return false;
        }

        bool include=isSubsetSum_rec(arr,target,index+1,sum+arr[index]);
        bool exclude=isSubsetSum_rec(arr,target,index+1,sum);
        return include||exclude;
    }
    bool isSubsetSum(vector<int> &arr, int target){
        return isSubsetSum_rec(arr, target,0,0);
    }
};
*/

class Solution {
public:
  bool isSubsetSum_rec(vector<int> &arr, int target, int index, int sum,
                       vector<vector<int>> &dp) {
    if (sum == target) {
      return true;
    }

    if (sum < 0 || sum > target) {
      return 0;
    }

    if (index >= arr.size()) {
      return false;
    }
    if (dp[index][sum] != -1) {
      return dp[index][sum];
    }

    bool include =
        isSubsetSum_rec(arr, target, index + 1, sum + arr[index], dp);
    bool exclude = isSubsetSum_rec(arr, target, index + 1, sum, dp);
    return dp[index][sum] = include || exclude;
  }
  bool isSubsetSum(vector<int> &arr, int target) {
    vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));
    return isSubsetSum_rec(arr, target, 0, 0, dp);
  }
};

int main() {
  cout << "Subset sum equals to target" << endl;
  vector<int> arr = {1, 2, 7, 3};
  // vector<int> arr = {2, 3, 5};
  int target = 6;
  Solution sol;
  cout << sol.isSubsetSum(arr, target);
  return 0;
}