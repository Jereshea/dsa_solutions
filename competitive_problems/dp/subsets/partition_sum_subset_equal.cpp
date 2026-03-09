/************
Partition equal subset sum

Given an array arr of n integers, return true if the array can be partitioned
into two subsets such that the sum of elements in both subsets is equal else
return false.


Example 1

Input: arr = [1, 10, 21, 10]

Output: True

Explanation: The array can be partitioned as [1, 10, 10] and [21].

Example 2

Input: arr = [1, 2, 3, 5]

Output: False

Explanation: The array cannot be partitioned into equal sum subsets.
**************/
#include <bits/stdc++.h>
using namespace std;

/*
// Recursion
class Solution{
public:
    bool equalPartition_rec(int n, vector<int> arr, int index,int sum,int
target){ if(sum==target){ return true;
        }
        if(index >= n){
            return false;
        }

        int include=equalPartition_rec(n, arr,index+1,sum+arr[index], target);
        int exclude=equalPartition_rec(n, arr,index+1,sum,target);

        return include||exclude;

    }
    bool equalPartition(int n, vector<int> arr) {
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        if(sum%2 != 0){
            return false;
        }
        return equalPartition_rec(n, arr,0,0,sum/2);
    }
};
*/

class Solution {
public:
  int equalPartition_rec(int n, vector<int> arr, int index, int sum, int target,
                         vector<vector<int>> &dp) {
    if (sum == target) {
      return 1;
    }

    if (sum > target) {
      return 0;
    }
    if (index >= n) {
      return 0;
    }

    if (dp[index][sum] != -1) {
      return dp[index][sum];
    }

    int include =
        equalPartition_rec(n, arr, index + 1, sum + arr[index], target, dp);
    int exclude = equalPartition_rec(n, arr, index + 1, sum, target, dp);

    return dp[index][sum] = include || exclude;
  }
  bool equalPartition(int n, vector<int> arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
      sum += arr[i];
    }
    if (sum % 2 != 0) {
      return false;
    }
    vector<vector<int>> dp(n, vector<int>((sum / 2) + 1, -1));
    return equalPartition_rec(n, arr, 0, 0, sum / 2, dp);
  }
};

int main() {
  // your code goes here
  cout << "Partition equal subset sum" << endl;
  vector<int> arr = {1, 10, 21, 10};
  // 	vector<int> arr = {1, 2, 3, 5};
  int n = arr.size();
  Solution sol;
  cout << sol.equalPartition(n, arr);
}
