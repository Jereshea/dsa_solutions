/******************************************************************************

Partition Equal Subset Sum

You are given an array 'ARR' of 'N' positive integers. Your task is to find if
we can partition the given array into two subsets such that the sum of elements
in both subsets is equal.

For example, let’s say the given array is [2, 3, 3, 3, 4, 5], then the array can
be partitioned as [2, 3, 5], and [3, 3, 4] with equal sum 10.

Follow Up:

Can you solve this using not more than O(S) extra space, where S is the sum of
all elements of the given array?

Sample Input 1:
2
6
3 1 1 2 2 1
5
5 6 5 11 6
Sample Output 1:
true
false
Explanation Of Sample Input 1:
For the first test case, the array can be partitioned as ([2,1,1,1] and [3, 2])
or ([2,2,1], and [1,1,3]) with sum 5.

For the second test case, the array can’t be partitioned.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // memoization
  int subset(vector<int> &grid, int k, int index, int curr_sum,
             vector<vector<int>> &dp_array) {
    if (curr_sum == k) {
      return 1;
    }

    if (index >= grid.size() || index < 0) {
      return 0;
    }

    if (dp_array[index][curr_sum] != -1) {
      return dp_array[index][curr_sum];
    }

    int include = subset(grid, k, index + 1, grid[index] + curr_sum, dp_array);
    int exclude = subset(grid, k, index + 1, curr_sum, dp_array);

    dp_array[index][curr_sum] = include || exclude;
    return dp_array[index][curr_sum];
  }

  int subset_equal_to_k(vector<int> &grid, int n) {
    int index = 0;

    int k = 0;
    for (int i = 0; i < n; i++) {
      k += grid[i];
    }
    if (k % 2 != 0) {
      return false;
    } else {
      k = k / 2;
      vector<vector<int>> dp_array(grid.size(), vector<int>(k + 1, -1));
      return subset(grid, k, index, 0, dp_array);
    }
  }
};

int main() {
  cout << "Partition Equal Subset Sum" << endl;
  vector<int> grid = {3, 1, 1, 2, 2, 1};
  Solution sol;
  cout << sol.subset_equal_to_k(grid, grid.size());

  return 0;
}