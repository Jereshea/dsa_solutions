/******************************************************************************

Grid unique paths

Given two integers m and n, representing the number of rows and columns of a 2d
array named matrix. Return the number of unique ways to go from the top-left
cell (matrix[0][0]) to the bottom-right cell (matrix[m-1][n-1]).

 Movement is allowed only in two directions from a cell: right and bottom.


Example 1

Input: m = 3, n = 2

Output: 3

Explanation:

There are 3 unique ways to go from the top left to the bottom right cell.

1) right -> down -> down

2) down -> right -> down

3) down -> down -> right

Example 2

Input: m = 2, n = 4

Output: 4

Explanation:

There are 4 unique ways to go from the top left to the bottom right cell.

1) down -> right -> right -> right

2) right -> down -> right -> right

3) right -> right -> down -> right

4) right -> right -> right -> down

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
// Recursion
class Solution {
public:
    int uniquePaths_rec(int m, int n, int cur_row, int cur_col){
        if(cur_row == m-1 && cur_col == n-1){
            return 1;
        }

        if(cur_row >=m || cur_col >= n){
            return 0;
        }

        int move_left=uniquePaths_rec(m,n,cur_row, cur_col+1);
        int move_down=uniquePaths_rec(m,n,cur_row+1,cur_col);

        return move_left+move_down;
    }
    int uniquePaths(int m, int n) {
        return uniquePaths_rec(m,n,0,0);
    }
};
*/
class Solution {
public:
  int uniquePaths_rec(int m, int n, int cur_row, int cur_col,
                      vector<vector<int>> &dp) {

    if (cur_row >= m || cur_col >= n) {
      return 0;
    }
    if (dp[cur_row][cur_col] != -1) {
      return dp[cur_row][cur_col];
    }
    if (cur_row == m - 1 && cur_col == n - 1) {
      return 1;
    }
    int move_left = uniquePaths_rec(m, n, cur_row, cur_col + 1, dp);
    int move_down = uniquePaths_rec(m, n, cur_row + 1, cur_col, dp);

    return dp[cur_row][cur_col] = move_left + move_down;
  }
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return uniquePaths_rec(m, n, 0, 0, dp);
  }
};
int main() {
  std::cout << "Grid unique paths" << endl;
  int m = 2;
  int n = 4;
  Solution sol;
  cout << sol.uniquePaths(m, n);
  return 0;
}