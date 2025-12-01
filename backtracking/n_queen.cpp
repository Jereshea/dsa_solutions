/******************************************************************************

N Queen Problem:

Given an integer n, place n queens on an n × n chessboard such that no two
queens attack each other. A queen can attack another queen if they are placed in
the same row, the same column, or on the same diagonal.

Find all possible distinct arrangements of the queens on the board that satisfy
these conditions.

The output should be an array of solutions, where each solution is represented
as an array of integers of size n, and the i-th integer denotes the column
position of the queen in the i-th row. If no solution exists, return an empty
array.

Examples:

Input:  n = 4
Output: [[2, 4, 1, 3], [3, 1, 4, 2]]

Approach:
1) Maintain an array is_queen_present
2) Check for issafe, when positioning a new queen
    a) No other queens should be in the same row
    b) No other queens should be in the same column
    c) No other queens should be in their diagonal indexes

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
Board (OR) is_queen_present
0 q 0 0
0 0 0 q
q 0 0 0
0 0 q 0

to_check_row_queens: col=2; to_check=(1,0) (1,1) (1,2)
to_check_col_queens: col=2; to_check=(0,2) (1,2) (2,2) (3,2)

Diagonal elements:
Consider (1,2)
    Lower diagonal elements
    0,1
    Upper diagonal elements
    2,1
    3,0
*/
bool issafe(int row, int col, int n, vector<vector<int>> &is_queen_present) {
  int x, y;
  // No elelment should be in the same row, we are positioning from the left to
  // right, so checking the availability of queens in row till the cuur row
  // index is fine
  x = row;
  y = 0;
  while (y < col) {
    if (is_queen_present[x][y] == 1) {
      return false;
    }
    y++;
  }

  // Check if any other queen is in the same col
  x = 0;
  y = col;

  while (x < n) {
    if (is_queen_present[x][y] == 1) {
      return false;
    }
    x++;
  }

  // To check the diagonal elements
  // Upper diagonal
  x = row - 1;
  y = col - 1;

  while (x >= 0 && y >= 0) {
    if (is_queen_present[x][y] == 1) {
      return false;
    }
    x--;
    y--;
  }

  // Lower diagonal
  x = row + 1;
  y = col - 1;

  while (x < n && y >= 0) {
    if (is_queen_present[x][y] == 1) {
      return false;
    }
    x++;
    y--;
  }

  return true;
}

void solve(int col, int n, vector<vector<int>> &is_queen_present,
           vector<vector<int>> &output) {
  if (col == n) {
    // To print the entire board for all the cases
    vector<int> partial_output;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        // partial_output.push_back(is_queen_present[i][j]);
        if (is_queen_present[i][j] == 1) {
          partial_output.push_back(j + 1);
        }
        // cout<<is_queen_present[i][j]<<" ";
      }
    }
    // cout<<endl;
    output.push_back(partial_output);
  }
  for (int i = 0; i < n; i++) {

    if (issafe(i, col, n, is_queen_present)) {
      is_queen_present[i][col] = 1;
      solve(col + 1, n, is_queen_present, output);
      is_queen_present[i][col] = 0;
    }
  }
}

void n_queen(int &n, vector<vector<int>> &output) {

  vector<vector<int>> is_queen_present(n, vector<int>(n, 0));
  vector<int> partial_output;
  solve(0, n, is_queen_present, output);
}

int main() {
  cout << "N Queen Problem" << endl;
  int n = 4;
  vector<vector<int>> output;
  n_queen(n, output);
  sort(output.begin(), output.end()); // If wanted in the sorted order
  for (auto &row : output) {
    for (int x : row) {
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}