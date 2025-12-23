/******************************************************************************

Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you
climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int climbing_stairs(int n, vector<int> &dp_array) {
  if (n == 0 || n == 1) {
    return n;
  }

  int prev1 = 1;
  int prev2 = 0;
  for (int i = 2; i <= n; i++) {
    int curr = prev1 + prev2;
    prev2 = prev1;
    prev1 = curr;
  }

  return prev1;
}
int main() {
  cout << "Climbing Stairs";
  int n = 3;
  vector<int> dp_array(n + 1, -1);
  cout << endl << endl << climbing_stairs(n, dp_array) << endl;

  return 0;
}