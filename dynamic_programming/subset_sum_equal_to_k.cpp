/******************************************************************************

Subset Sum Equal To K

You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’.
Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.

Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise,
return false.

For Example :
If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4.
These are {1,3} and {4}. Hence, return true. Detailed explanation ( Input/output
format, Notes, Images ) Constraints: 1 <= T <= 5 1 <= N <= 10^3 0 <= ARR[i] <=
10^9 0 <= K <= 10^3

Time Limit: 1 sec
Sample Input 1:
2
4 5
4 3 2 1
5 4
2 5 1 6 7
Sample Output 1:
true
false
Explanation For Sample Input 1:
In example 1, ‘ARR’ is {4,3,2,1} and ‘K’ = 5. There exist 2 subsets with sum
= 5. These are {4,1} and {3,2}. Hence, return true. In example 2, ‘ARR’ is
{2,5,1,6,7} and ‘K’ = 4. There are no subsets with sum = 4. Hence, return false.
Sample Input 2:
2
4 4
6 1 2 1
5 6
1 7 2 9 10
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  /*
  // Recursion
  int subset(vector<int> &grid, int k, int index, int curr_sum){
      if(curr_sum==k){
          return 1;
      }

      if (curr_sum > k) {
        return 0;
    }

      if(index>=grid.size() || index<0){
          return 0;
      }

      int include=subset(grid, k, index+1, grid[index]+curr_sum);
      int exclude=subset(grid, k, index+1, curr_sum);

      return include||exclude;
  }

  int subset_equal_to_k(vector<int> &grid, int k){
      int index=0;
      return subset(grid, k, index, 0);
  }
  */

  // memoization
  int subset(vector<int> &grid, int k, int index, int curr_sum,
             vector<vector<int>> &dp_array) {
    if (curr_sum == k) {
      return 1;
    }

    if (curr_sum > k) {
      return 0;
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

  int subset_equal_to_k(vector<int> &grid, int k) {
    int index = 0;
    vector<vector<int>> dp_array(grid.size(), vector<int>(k + 1, -1));
    return subset(grid, k, index, 0, dp_array);
  }
};

int main() {
  cout << "Subset Sum Equal To K" << endl;
  int k = 2;
  vector<int> grid = {4, 3, 2, 1};
  Solution sol;
  cout << sol.subset_equal_to_k(grid, k);

  return 0;
}