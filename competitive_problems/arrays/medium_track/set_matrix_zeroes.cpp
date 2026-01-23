/******************************************************************************

Set Matrix Zeroes

Given an m x n integer matrix matrix, if an element is 0, set its entire row and
column to 0. You must do it in place.


Example 1

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]

Output: [[1,0,1],[0,0,0],[1,0,1]]

Explanation:

Element at position (1,1) is 0, so set entire row 1 and column 1 to 0.

Example 2

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]

Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Explanation:

There are two zeroes: (0,0) and (0,3).

Row 0 → all elements become 0
Column 0 and column 3 → all elements become 0
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    // Your code goes here
    // Maintain map to check if the row or col is filled with 0
    unordered_map<int, int> row_check;
    unordered_map<int, int> col_check;

    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[i][j] == 0) {
          row_check[i] = 1;
          col_check[j] = 1;
        }
      }
    }

    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[i][j] != 0) {
          // if(row_check[i]==1 || col_check[j]==1){
          if (row_check.count(i) || col_check.count(j)) {
            matrix[i][j] = 0;
          }
        }
      }
    }
  }
};

int main() {
  cout << "Set Matrix Zeroes" << endl;
  vector<vector<int>> matrix;
  matrix.push_back({0, 1, 2, 0});
  matrix.push_back({3, 4, 5, 2});
  matrix.push_back({1, 3, 1, 5});
  Solution sol;
  sol.setZeroes(matrix);
  for (auto &m : matrix) {
    for (auto &x : m) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}