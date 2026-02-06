/******************************************************************************
Number of islands

Given a grid of size N x M (N is the number of rows and M is the number of
columns in the grid) consisting of '0's (Water) and ‘1's(Land). Find the number
of islands.

An island is surrounded by water and is formed by connecting adjacent lands
horizontally or vertically or diagonally i.e., in all 8 directions.


Example 1
Input: grid = [ ["1", "1", "1", "0", "1"], ["1", "0", "0", "0", "0"], ["1", "1",
"1", "0", "1"], ["0", "0", "0", "1", "1"] ]

Output: 2

Explanation: This grid contains 2 islands. Each '1' represents a piece of land,
and the islands are formed by connecting adjacent lands horizontally or
vertically. Despite some islands having a common edge, they are considered
separate islands because there is no land connectivity in any of the eight
directions between them. Therefore, the grid contains 2 islands.

Example 2

Input: grid = [ ["1", "0", "0", "0", "1"], ["0", "1", "0", "1", "0"], ["0", "0",
"1", "0", "0"], ["0", "1", "0", "1"," 0"] ]

Output: 1

Explanation: In the given grid, there's only one island as all the '1's are
connected either horizontally, vertically, or diagonally, forming a single
contiguous landmass surrounded by water on all sides.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void dfs_traversal(int cur_row, int cur_col, int row, int col,
                     vector<int> &possible_row, vector<int> &possible_col,
                     vector<vector<char>> &grid, vector<vector<int>> &visited) {
    visited[cur_row][cur_col] = 1;

    for (int i = 0; i < 8; i++) {
      int new_row = cur_row + possible_row[i];
      int new_col = cur_col + possible_col[i];

      if (new_row >= 0 && new_row < row && new_col >= 0 && new_col < col &&
          visited[new_row][new_col] == 0 && grid[new_row][new_col] == '1') {
        dfs_traversal(new_row, new_col, row, col, possible_row, possible_col,
                      grid, visited);
      }
    }
  }
  int numIslands(vector<vector<char>> &grid) {
    int result = 0;
    int row = grid.size();
    int col = grid[0].size();

    // dfs_traversal
    vector<vector<int>> visited(row, vector<int>(col, 0));

    vector<int> possible_row = {-1, 1, 0, 0, -1, -1, 1, 1};
    vector<int> possible_col = {0, 0, -1, 1, -1, 1, -1, 1};
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (visited[i][j] == 0 && grid[i][j] == '1') {
          result = result + 1;
          dfs_traversal(i, j, row, col, possible_row, possible_col, grid,
                        visited);
        }
      }
    }
    return result;
  }
};

int main() {
  cout << "Number of islands" << endl;
  vector<vector<char>> grid = {{'1', '0', '0', '0', '1'},
                               {'0', '1', '0', '1', '0'},
                               {'0', '0', '1', '0', '0'},
                               {'0', '1', '0', '1', '0'}};
  Solution sol;
  cout << sol.numIslands((grid));
  return 0;
}