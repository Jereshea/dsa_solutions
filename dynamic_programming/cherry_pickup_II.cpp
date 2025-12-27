/******************************************************************************

Cherry Pickup II

You are given a rows x cols matrix grid representing a field of cherries where
grid[i][j] represents the number of cherries that you can collect from the (i,
j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following
the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i +
1, j + 1). When any robot passes through a cell, It picks up all cherries, and
the cell becomes an empty cell. When both robots stay in the same cell, only one
takes the cherries. Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.

Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue
respectively. Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12. Cherries taken
by Robot #2, (1 + 5 + 5 + 1) = 12. Total of cherries: 12 + 12 = 24.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  /*
  // Recursion
  int pickup(int row, int col, int curr_row, int robot1_col, int robot2_col,
  vector<vector<int>> &grid){ if(robot1_col>=col || robot2_col>=col ||
  curr_row>=row || robot1_col<0 || robot2_col<0 || curr_row<0){ return INT_MIN;
      }

      if(curr_row==row-1){
          if(robot1_col==robot2_col){
              return grid[curr_row][robot1_col];
          }
          else{
              return grid[curr_row][robot1_col]+grid[curr_row][robot2_col];
          }
      }

      int maxi=INT_MIN;
      int ans=0;
      int result;

      for(int i=-1; i<=1;i++){
          for(int j=-1; j<=1;j++){
              if(robot1_col==robot2_col){
                  if(curr_row+1<row && robot1_col+i<col && robot2_col+j<col &&
  curr_row+1>=0 && robot1_col+i>=0 && robot2_col+j>=0){
                      ans=grid[curr_row][robot1_col]+ pickup(row, col,
  curr_row+1, robot1_col+i,robot2_col+j, grid);
                  }
              }else{
                  if(curr_row+1<row && robot1_col+i<col && robot2_col+j<col &&
  curr_row+1>=0 && robot1_col+i>=0 && robot2_col+j>=0){
                      ans=grid[curr_row][robot1_col]+grid[curr_row][robot2_col]+
  pickup(row, col, curr_row+1, robot1_col+i,robot2_col+j, grid);
                  }
              }
              maxi=max(maxi,ans);
          }
      }
      return maxi;
  }
  int cherryPickup(vector<vector<int>>& grid) {
      int row=grid.size();
      int col=grid[0].size();
      int robot1_col=0;
      int robot2_col=col-1;
      return pickup(row, col, 0, robot1_col, robot2_col,grid);
  }
  */

  // Memoization
  int pickup(int row, int col, int curr_row, int robot1_col, int robot2_col,
             vector<vector<int>> &grid, vector<vector<vector<int>>> &dp_array) {
    if (robot1_col >= col || robot2_col >= col || curr_row >= row ||
        robot1_col < 0 || robot2_col < 0 || curr_row < 0) {
      return -1e9;
    }

    if (curr_row == row - 1) {
      if (robot1_col == robot2_col) {
        return grid[curr_row][robot1_col];
      } else {
        return grid[curr_row][robot1_col] + grid[curr_row][robot2_col];
      }
    }

    if (dp_array[curr_row][robot1_col][robot2_col] != -1e9) {
      return dp_array[curr_row][robot1_col][robot2_col];
    }

    int maxi = -1e9;
    int ans = -1e9;
    int result;

    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (robot1_col == robot2_col) {
          ans = grid[curr_row][robot1_col] +
                pickup(row, col, curr_row + 1, robot1_col + i, robot2_col + j,
                       grid, dp_array);
        } else {
          ans = grid[curr_row][robot1_col] + grid[curr_row][robot2_col] +
                pickup(row, col, curr_row + 1, robot1_col + i, robot2_col + j,
                       grid, dp_array);
        }
        maxi = max(maxi, ans);
      }
    }
    dp_array[curr_row][robot1_col][robot2_col] = maxi;
    return dp_array[curr_row][robot1_col][robot2_col];
  }
  int cherryPickup(vector<vector<int>> &grid) {
    int row = grid.size();
    int col = grid[0].size();
    int robot1_col = 0;
    int robot2_col = col - 1;
    vector<vector<vector<int>>> dp_array(
        row, vector<vector<int>>(col, vector<int>(col, -1e9)));
    return pickup(row, col, 0, robot1_col, robot2_col, grid, dp_array);
  }
};

int main() {
  cout << "Cherry Pickup II" << endl;
  vector<vector<int>> grid = {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};
  Solution sol;
  cout << sol.cherryPickup(grid);

  return 0;
}