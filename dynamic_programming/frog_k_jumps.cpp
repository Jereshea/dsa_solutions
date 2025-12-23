/******************************************************************************
Frog Jump with up to k steps and minimum energy (Dynamic Programming)
There is a frog standing at index 0 of a staircase with N steps.
Each step has a certain height, given in an array HEIGHT of size N.
The frog wants to reach the last step (index N−1).
Rules:
From step i, the frog can jump to:
step i + 1, or
step i + 2
.
.
.
step i + k
The energy cost of a jump from step i to step j is:

|HEIGHT[i] − HEIGHT[j]|
Task:
Find the minimum total energy required for the frog to reach the last step. The
max k is 4 Example:

Input:
HEIGHT = [10, 20, 30, 10]
k = 4
Output:
20
Explanation:
Jump from step 0 → 3: cost = |10 − 10| = 0

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int frog_jump(vector<int> &cost, int k, int n, vector<int> &dp_array) {
  if (n == 0) {
    return 0;
  }

  if (dp_array[n] != INT_MAX) {
    return dp_array[n];
  }

  for (int i = 1; i <= k; i++) {
    if (n - i >= 0) {
      int jump_k_1 =
          frog_jump(cost, k, n - i, dp_array) + abs(cost[n] - cost[n - i]);
      // cout<<" "<<jump_k_1<<" ";
      dp_array[n] = min(dp_array[n], jump_k_1);
    }
  }

  return dp_array[n];
}

int main() {
  cout << "Frog Jump with up to k steps and minimum energy";
  vector<int> cost = {10, 20, 30, 50};
  int size = cost.size();
  int k = 4;
  vector<int> dp_array(size, INT_MAX);
  cout << endl << endl << "Result: " << frog_jump(cost, k, size - 1, dp_array);

  return 0;
}