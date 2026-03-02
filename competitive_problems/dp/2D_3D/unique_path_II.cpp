/******************************************************************************

Unique paths II

Given an m x n 2d array named matrix, where each cell is either 0 or 1. Return
the number of unique ways to go from the top-left cell (matrix[0][0]) to the
bottom-right cell (matrix[m-1][n-1]). A cell is blocked if its value is 1, and
no path is possible through that cell.

Movement is allowed in only two directions from a cell - right and bottom.


Example 1

Input: matrix = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]

Output: 2

Explanation:

The two possible paths are:

1) down -> down-> right -> right

2) right -> right -> down -> down

Example 2

Input: matrix = [[0, 0, 0], [0, 0, 1], [0, 1, 0]]

Output: 0

Explanation:

There is no way to reach the bottom-right cell.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
// Recursion
class Solution {
public:
    int uniquePathsWithObstacles_rec(vector<vector<int>>& matrix, int row,int
col,int cur_row,int cur_col){ if(cur_row== row-1 && cur_col==col-1){ return 1;
        }

        if(cur_row >= row || cur_col >= col){
            return 0;
        }

        if(matrix[cur_row][cur_col]==1){
            return 0;
        }


        int move_right=uniquePathsWithObstacles_rec(matrix, row,
col,cur_row,cur_col+1); int move_down=uniquePathsWithObstacles_rec(matrix, row,
col,cur_row+1,cur_col);

        return move_right+move_down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        if(matrix[row-1][col-1]==0)
            return uniquePathsWithObstacles_rec(matrix, row, col,0,0);
        else
            return 0;
    }
};
*/
class Solution {
public:
  int uniquePathsWithObstacles_rec(vector<vector<int>> &matrix, int row,
                                   int col, int cur_row, int cur_col,
                                   vector<vector<int>> &dp) {

    if (cur_row >= row || cur_col >= col) {
      return 0;
    }

    if (cur_row == row - 1 && cur_col == col - 1) {
      return 1;
    }

    if (matrix[cur_row][cur_col] == 1) {
      return 0;
    }

    if (dp[cur_row][cur_col] != -1) {
      return dp[cur_row][cur_col];
    }

    int move_right = uniquePathsWithObstacles_rec(matrix, row, col, cur_row,
                                                  cur_col + 1, dp);
    int move_down = uniquePathsWithObstacles_rec(matrix, row, col, cur_row + 1,
                                                 cur_col, dp);

    return dp[cur_row][cur_col] = move_right + move_down;
  }
  int uniquePathsWithObstacles(vector<vector<int>> &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    if (matrix[row - 1][col - 1] == 0) {
      vector<vector<int>> dp(row, vector<int>(col, -1));
      return uniquePathsWithObstacles_rec(matrix, row, col, 0, 0, dp);
    } else
      return 0;
  }
};
int main() {
  std::cout << "Unique paths II" << endl;
  vector<vector<int>> matrix = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  Solution sol;
  cout << sol.uniquePathsWithObstacles(matrix);
  return 0;
}