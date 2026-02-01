/*************
Surrounded Regions

You are given a matrix mat of size N x M where each cell contains either 'O' or
'X'.

Your task is to replace all 'O' cells that are completely surrounded by 'X' with
'X'.



Rules:

An 'O' (or a group of connected 'O's) is considered surrounded if it is not
connected to any border of the matrix. Two 'O' cells are considered connected if
they are adjacent horizontally or vertically (not diagonally). A region of
connected 'O's that touches the border (i.e., first row, last row, first column,
or last column) is not surrounded and should not be changed.

Example 1



Input: mat = [ ["X", "X", "X", "X"], ["X", "O", "O", "X"], ["X", "X", "O", "X"],
["X", "O", "X", "X"] ]

Output: [ ["X", "X", "X", "X"], ["X", "X", "X", "X"], ["X", "X", "X", "X"],
["X", "O", "X", "X"] ]

Explanation:



The 'O' cells at positions (1,1), (1,2), (2,2), and (3,1) are surrounded by 'X'
cells in all directions (horizontally and vertically).

However, the 'O' region at (3,1) is adjacent to an edge of the board, so it
cannot be completely surrounded by 'X' cells. Therefore, it remains unchanged.
*************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void dfs_traversal(int cur_row, int cur_col, vector<vector<char>> &mat,
                     vector<vector<int>> &visited, int row, int col) {

    visited[cur_row][cur_col] = 1;
    vector<int> possible_row = {-1, 1, 0, 0};
    vector<int> possible_col = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++) {
      int new_row = cur_row + possible_row[i];
      int new_col = cur_col + possible_col[i];

      if (new_row >= 0 && new_row < row && new_col >= 0 && new_col < col &&
          mat[new_row][new_col] == 'O') {
        visited[new_row][new_col] = 1;
        dfs_traversal(new_row, new_col, mat, visited, row, col);
      }
    }
  }
  vector<vector<char>> fill(vector<vector<char>> mat) {
    int row = mat.size();
    int col = mat[0].size();

    vector<vector<int>> visited(row, vector<int>(col, 0));

    // first row and last row
    for (int i = 0; i < col; i++) {
      // first row
      if (mat[0][i] == 'O') {
        visited[0][i] = 1;
        dfs_traversal(0, i, mat, visited, row, col);
      }

      // last row
      if (mat[col - 1][i] == 'O') {
        visited[col - 1][i] = 1;
        dfs_traversal(col - 1, i, mat, visited, row, col);
      }
    }

    // first col and last col
    for (int i = 0; i < row; i++) {
      // first col
      if (mat[i][0] == 'O') {
        visited[i][0] = 1;
        dfs_traversal(i, 0, mat, visited, row, col);
      }

      // last col
      if (mat[i][row - 1] == 'O') {
        visited[i][row - 1] = 1;
        dfs_traversal(i, row - 1, mat, visited, row, col);
      }
    }

    // Update the mat
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (visited[i][j] == 0 && mat[i][j] == 'O') {
          mat[i][j] = 'X';
        }
      }
    }
    return mat;
  }
};

int main() {
  // your code goes here
  vector<vector<char>> mat = {{'X', 'X', 'X', 'X'},
                              {'X', 'O', 'O', 'X'},
                              {'X', 'X', 'O', 'X'},
                              {'X', 'O', 'X', 'X'}};
  Solution sol;
  vector<vector<char>> result = sol.fill(mat);

  for (auto &m : result) {
    for (auto &x : m) {
      cout << x << " ";
    }
    cout << endl;
  }
}
