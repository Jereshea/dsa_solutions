/**********************
Number of enclaves


Given an N x M binary matrix grid, where 0 represents a sea cell and 1
represents a land cell. A move consists of walking from one land cell to another
adjacent (4-directionally) land cell or walking off the boundary of the grid.
Find the number of land cells in the grid for which we cannot walk off the
boundary of the grid in any number of moves.


Example 1



Input: grid = [[0, 0, 0, 0], [1, 0, 1, 0], [0, 1, 1, 0], [0, 0, 0, 0]]

Output: 3

Explanation:



The highlighted cells represents the land cells.

Example 2



Input: grid = [[0, 0, 0, 1],[0, 0, 0, 1], [0, 1, 1, 0], [0, 0, 1, 0], [0, 0, 0,
0]]

Output:3

Explanation:



The highlighted cells represents the land cells.
***********************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void dfs_traversal(int cur_row, int cur_col, vector<vector<int>> &grid,
                     vector<vector<int>> &visited, int row, int col) {
    visited[cur_row][cur_col] = 1;

    vector<int> possible_rows = {-1, 1, 0, 0};
    vector<int> possible_cols = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++) {
      int new_row = cur_row + possible_rows[i];
      int new_col = cur_col + possible_cols[i];

      if (new_row >= 0 && new_row < row && new_col >= 0 && new_col < col &&
          grid[new_row][new_col] == 1 && visited[new_row][new_col] == 0) {
        dfs_traversal(new_row, new_col, grid, visited, row, col);
      }
    }
  }
  int numberOfEnclaves(vector<vector<int>> &grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> visited(row, vector<int>(col, 0));

    // Given it can be traversed only from boundary
    // first row and last row
    for (int i = 0; i < col; i++) {
      if (grid[0][i] == 1 && visited[0][i] == 0) {
        dfs_traversal(0, i, grid, visited, row, col);
      }

      if (grid[row - 1][i] == 1 && visited[row - 1][i] == 0) {
        dfs_traversal(row - 1, i, grid, visited, row, col);
      }
    }

    // first col and last col
    for (int i = 0; i < row; i++) {
      if (grid[i][0] == 1 && visited[i][0] == 0) {
        dfs_traversal(i, 0, grid, visited, row, col);
      }

      if (grid[i][col - 1] == 1 && visited[i][col - 1] == 0) {
        dfs_traversal(i, col - 1, grid, visited, row, col);
      }
    }

    int result = 0;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (grid[i][j] == 1 && visited[i][j] == 0) {
          result = result + 1;
        }
      }
    }
    return result;
  }
};

int main() {
  // your code goes here
  vector<vector<int>> grid = {
      {0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
  Solution sol;
  cout << sol.numberOfEnclaves(grid);
}
