/******************************************************************************
Frog Jump (Dynamic Programming)
There is a frog standing at index 0 of a staircase with N steps.
Each step has a certain height, given in an array HEIGHT of size N.
The frog wants to reach the last step (index N−1).
Rules:
From step i, the frog can jump to:
step i + 1, or
step i + 2
The energy cost of a jump from step i to step j is:

|HEIGHT[i] − HEIGHT[j]|
Task:
Find the minimum total energy required for the frog to reach the last step.
Example:

Input:
HEIGHT = [10, 20, 30, 10]

Output:
20
Explanation:
Jump from step 0 → 1: cost = |10 − 20| = 10
Jump from step 1 → 3: cost = |20 − 10| = 10
Total minimum energy = 10 + 10 = 20


Input: heights[] = [20, 30, 40, 20]
Output: 20
Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1
then 1 to 3: jump from stair 0 to 1: cost = |30 - 20| = 10 jump from stair 1 to
3: cost = |20 - 30|  = 10 Total Cost = 10 + 10 = 20

Input: heights[] = [30, 20, 50, 10, 40]
Output: 30
Explanation: Minimum cost will be incurred when frog jumps from stair 0 to 2
then 2 to 4: jump from stair 0 to 2: cost = |50 - 30| = 20 jump from stair 2 to
4: cost = |40 - 50|  = 10 Total Cost = 20 + 10 = 30
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int frog_jump(vector<int> &stones, int n, vector<int> &dp_array) {
  if (n == 0) {
    return stones[n];
  }

  if (n == 1) {
    return abs(stones[n] - stones[n - 1]);
  }
  if (dp_array[n] != INT_MAX) {
    return dp_array[n];
  }
  int jump_1 =
      frog_jump(stones, n - 1, dp_array) + abs(stones[n] - stones[n - 1]);
  int jump_2 = INT_MAX;
  if (n > 1) {
    jump_2 =
        frog_jump(stones, n - 2, dp_array) + abs(stones[n] - stones[n - 2]);
  }

  dp_array[n] = min(jump_1, jump_2);
  return dp_array[n];
}

int main() {
  cout << "Frog Jump";
  vector<int> stones = {20, 30, 40, 20};
  int size = stones.size();
  vector<int> dp_array(size, INT_MAX);
  cout << endl << endl << frog_jump(stones, size - 1, dp_array) << endl;

  return 0;
}