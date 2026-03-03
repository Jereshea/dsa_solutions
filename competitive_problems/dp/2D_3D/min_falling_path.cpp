/******************************************************************************

Minimum Falling Path Sum

Given a 2d array called matrix consisting of integer values. Return the minimum
path sum that can be obtained by starting at any cell in the first row and
ending at any cell in the last row.



Movement is allowed only to the bottom, bottom-right, or bottom-left cell of the
current cell.


Example 1

Input: matrix = [[1, 2, 10, 4], [100, 3, 2, 1], [1, 1, 20, 2], [1, 2, 2, 1]]

Output: 6

Explanation:

One optimal route can be:-

Start at 1st cell of 1st row -> bottom-right -> bottom -> bottom-left.

Example 2

Input: matrix = [[1, 4, 3, 1], [2, 3, -1, -1], [1, 1, -1, 8]]

Output: -1

Explanation:

One optimal route can be:-

Start at 4th cell of 1st row -> bottom-left -> bottom.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
// Recursion
class Solution {
public:
    int minFallingPathSum_rec(vector<vector<int>>& matrix, int cur_row, int
cur_col, int row, int col){ if(cur_row >= row || cur_row < 0 || cur_col >= col
|| cur_col <0){ return INT_MAX;
        }

        if(cur_row==row-1){
            return matrix[cur_row][cur_col];
        }

        int bottom=INT_MAX;
        int bottom_left=INT_MAX;
        int bottom_right=INT_MAX;

        int move_bottom=minFallingPathSum_rec(matrix, cur_row+1, cur_col, row,
col); if(move_bottom != INT_MAX){ bottom=matrix[cur_row][cur_col]+move_bottom;
        }
        int move_bottom_left=minFallingPathSum_rec(matrix, cur_row+1, cur_col-1,
row, col); if(move_bottom_left != INT_MAX){
            bottom_left=matrix[cur_row][cur_col]+move_bottom_left;
        }
        int move_bottom_right=minFallingPathSum_rec(matrix, cur_row+1,
cur_col+1, row, col); if(move_bottom_right != INT_MAX){
            bottom_right=matrix[cur_row][cur_col]+move_bottom_right;
        }
        return min(bottom,min(bottom_left, bottom_right));

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int result=INT_MAX;
        for(int i=0;i<col;i++){
            result=min(result, minFallingPathSum_rec(matrix, 0, i, row, col));
        }
        return result;
    }
};
*/

class Solution {
public:
  int minFallingPathSum_rec(vector<vector<int>> &matrix, int cur_row,
                            int cur_col, int row, int col,
                            vector<vector<int>> &dp) {
    if (cur_row >= row || cur_row < 0 || cur_col >= col || cur_col < 0) {
      return INT_MAX;
    }

    if (cur_row == row - 1) {
      return matrix[cur_row][cur_col];
    }

    if (dp[cur_row][cur_col] != INT_MAX) {
      return dp[cur_row][cur_col];
    }
    int bottom = INT_MAX;
    int bottom_left = INT_MAX;
    int bottom_right = INT_MAX;

    int move_bottom =
        minFallingPathSum_rec(matrix, cur_row + 1, cur_col, row, col, dp);
    if (move_bottom != INT_MAX) {
      bottom = matrix[cur_row][cur_col] + move_bottom;
    }
    int move_bottom_left =
        minFallingPathSum_rec(matrix, cur_row + 1, cur_col - 1, row, col, dp);
    if (move_bottom_left != INT_MAX) {
      bottom_left = matrix[cur_row][cur_col] + move_bottom_left;
    }
    int move_bottom_right =
        minFallingPathSum_rec(matrix, cur_row + 1, cur_col + 1, row, col, dp);
    if (move_bottom_right != INT_MAX) {
      bottom_right = matrix[cur_row][cur_col] + move_bottom_right;
    }
    return dp[cur_row][cur_col] = min(bottom, min(bottom_left, bottom_right));
  }
  int minFallingPathSum(vector<vector<int>> &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    int result = INT_MAX;
    vector<vector<int>> dp(row, vector<int>(col, INT_MAX));
    for (int i = 0; i < col; i++) {
      result = min(result, minFallingPathSum_rec(matrix, 0, i, row, col, dp));
    }
    return result;
  }
};
int main() {
  cout << "Minimum Falling Path Sum" << endl;
  vector<vector<int>> matrix = {
      {1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
  Solution sol;
  cout << sol.minFallingPathSum(matrix);

  return 0;
}