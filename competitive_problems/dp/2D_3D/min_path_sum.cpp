/******************************************************************************
Minimum Path Sum In a Grid

Given a m x n grid filled with non-negative numbers, find a path from top left
to bottom right, which minimizes the sum of all numbers along its path. Note:
You can only move either down or right at any point in time.

Input: grid = [[5,9,6],[11,5,2]]
Output: 21
Explanation: Minimum sum is achieved via path 5->9->5->2 i.e. 21.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
// Recursion
class Solution {
public:
    int uniquePaths_rec(vector<vector<int>>& grid, int row,int col,int
cur_row,int cur_col){ if(cur_row== row-1 && cur_col==col-1){ return
grid[cur_row][cur_col];
        }

        if(cur_row >= row || cur_col >= col){
            return -1;
        }

        int right=INT_MAX;
        int down=INT_MAX;
        int move_right=uniquePaths_rec(grid, row, col,cur_row,cur_col+1);
        if(move_right!=-1){
            right=grid[cur_row][cur_col]+move_right;
        }
        int move_down=uniquePaths_rec(grid, row, col,cur_row+1,cur_col);
        if(move_down!=-1){
            down=grid[cur_row][cur_col]+move_down;
        }

        return min(right,down);
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int result=uniquePaths_rec(grid, row, col,0,0);
        if(result!=INT_MAX){
            return result;
        }else{
            return 0;
        }
    }
};
*/

class Solution {
public:
  int uniquePaths_rec(vector<vector<int>> &grid, int row, int col, int cur_row,
                      int cur_col, vector<vector<int>> &dp) {
    if (cur_row == row - 1 && cur_col == col - 1) {
      return grid[cur_row][cur_col];
    }

    if (cur_row >= row || cur_col >= col) {
      return -1;
    }

    if (dp[cur_row][cur_col] != INT_MAX) {
      return dp[cur_row][cur_col];
    }

    int right = INT_MAX;
    int down = INT_MAX;
    int move_right = uniquePaths_rec(grid, row, col, cur_row, cur_col + 1, dp);
    if (move_right != -1) {
      right = grid[cur_row][cur_col] + move_right;
    }
    int move_down = uniquePaths_rec(grid, row, col, cur_row + 1, cur_col, dp);
    if (move_down != -1) {
      down = grid[cur_row][cur_col] + move_down;
    }

    return dp[cur_row][cur_col] = min(right, down);
  }
  int uniquePaths(vector<vector<int>> &grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, INT_MAX));
    int result = uniquePaths_rec(grid, row, col, 0, 0, dp);
    if (result != INT_MAX) {
      return result;
    } else {
      return 0;
    }
  }
};

int main() {
  std::cout << "Minimum Path Sum In a Grid" << endl;
  vector<vector<int>> grid = {{5, 9, 6}, {11, 5, 2}};
  Solution sol;
  cout << sol.uniquePaths(grid);
  return 0;
}