/******************************************************************************

Sudoko Solver:

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of
the grid. The '.' character indicates empty cells.



Example 1:


Input: board =
[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output:
[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]

hash map <row,map<char,bool>>
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool issafe(int i, int j,
              unordered_map<int, unordered_map<char, bool>> &row_values,
              unordered_map<int, unordered_map<char, bool>> &col_values,
              char ch, unordered_map<int, unordered_map<char, bool>> &box) {

    // k i row j col
    // 0,0 k
    if (row_values[i][ch] == true) {
      return false;
    }

    if (col_values[j][ch] == true) {
      return false;
    }

    int ind = (i / 3) * 3 + (j / 3);
    if (box[ind][ch] == true) {
      return false;
    }
    return true;
  }
  bool solve(vector<vector<char>> &board,
             unordered_map<int, unordered_map<char, bool>> &row_values,
             unordered_map<int, unordered_map<char, bool>> &col_values,
             unordered_map<int, unordered_map<char, bool>> &box) {
    int size = board.size();

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (board[i][j] == '.') {
          for (int k = 0; k < 9; k++) {
            char ch = k + '1';
            if (issafe(i, j, row_values, col_values, ch, box)) {
              board[i][j] = k + '1';
              row_values[i][board[i][j]] = true;
              col_values[j][board[i][j]] = true;
              box[(i / 3) * 3 + (j / 3)][board[i][j]] = true;

              if (solve(board, row_values, col_values, box)) {
                return true;
              }
              row_values[i][board[i][j]] = false;
              col_values[j][board[i][j]] = false;
              box[(i / 3) * 3 + (j / 3)][board[i][j]] = false;
              board[i][j] = '.';
            }
          }

          return false;
        }
      }
    }
    return true;
  }
  void solveSudoku(vector<vector<char>> &board) {
    // cout<<"check";
    // vector<vector<int>> board_int;
    int size = board.size();
    unordered_map<int, unordered_map<char, bool>> row_values;
    unordered_map<int, unordered_map<char, bool>> col_values;
    unordered_map<int, unordered_map<char, bool>> box;
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (board[i][j] != '.') {
          row_values[i][board[i][j]] = true;
          col_values[j][board[i][j]] = true;
          box[(i / 3) * 3 + (j / 3)][board[i][j]] = true;
        } else {
          row_values[i][board[i][j]] = false;
          col_values[j][board[i][j]] = false;
          box[(i / 3) * 3 + (j / 3)][board[i][j]] = false;
        }
      }
    }

    solve(board, row_values, col_values, box);
  }
};

int main() {
  cout << "Sudoku Solver" << endl;
  cout << "Input" << endl;
  vector<vector<char>> board;
  board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
           {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
           {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
           {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
           {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
           {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
           {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
           {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
           {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  for (auto &m : board) {
    for (char t : m) {
      cout << t << " ";
    }
  }
  cout << endl;
  cout << endl;
  Solution sol;
  sol.solveSudoku(board);
  cout << "Output" << endl;
  for (auto &m : board) {
    for (char t : m) {
      cout << t << " ";
    }
  }

  return 0;
}