/***********
Climbing stairs

Given an integer n, there is a staircase with n steps, starting from the 0th
step.

Determine the number of unique ways to reach the nth step, given that each move
can be either 1 or 2 steps at a time.


Example 1

Input: n = 2

Output: 2

Explanation:

There are 2 unique ways to climb to the 2nd step:

1) 1 step + 1 step

2) 2 steps

Example 2

Input: n = 3

Output: 3

Explanation:

There are 3 unique ways to climb to the 3rd step:

1) 1 step + 1 step + 1 step

2) 2 steps + 1 step

3) 1 step + 2 steps
*************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  /*
  // Recursion
  int climbingStair_rec(int n, int index){
      if(index==n){
          return 1;
      }
      if(index > n){
          return 0;
      }


      int step_1=climbingStair_rec(n,index+1);
      int step_2=climbingStair_rec(n,index+2);

      return step_1+step_2;

  }
  int climbStairs(int n) {
      return climbingStair_rec(n,0);
  }
  */

  // memoization
  int climbingStair_rec(int n, int index, vector<int> &dp) {

    if (index > n) {
      return 0;
    }
    if (index == n) {
      return 1;
    }

    if (dp[index] != -1) {
      return dp[index];
    }

    int step_1 = climbingStair_rec(n, index + 1, dp);
    int step_2 = climbingStair_rec(n, index + 2, dp);

    return dp[index] = step_1 + step_2;
  }
  int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    return climbingStair_rec(n, 0, dp);
  }
};

int main() {
  // your code goes here
  cout << "Climbing stairs" << endl;
  int n = 2;
  Solution sol;
  cout << sol.climbStairs(n);
}
