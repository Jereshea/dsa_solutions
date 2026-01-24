/******************************************************************************

Rotate matrix by 90 degrees:

Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise.



The rotation must be done in place, meaning the input 2D matrix must be modified
directly.


Example 1

Input: matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output: matrix = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]


*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void rotateMatrix(vector<vector<int>> &matrix) {
    /*
    1 2 3
    4 5 6
    7 8 9

    7 4 1
    8 5 2
    9 6 3

    Procedure:
    1) Transpose the Matrix
    2) Reverse each array
    */

    // Transpose
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = i + 1; j < matrix[i].size(); j++) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }

    // Reverse each row
    for (int i = 0; i < matrix.size(); i++) {
      int end = matrix[i].size() - 1;
      for (int j = 0; j < matrix[i].size() / 2; j++) {
        swap(matrix[i][j], matrix[i][end--]);
      }
    }
  }
};

int main() {
  cout << "Rotate matrix by 90 degrees" << endl;
  vector<vector<int>> matrix;
  matrix.push_back({1, 2, 3});
  matrix.push_back({4, 5, 6});
  matrix.push_back({7, 8, 9});
  Solution sol;
  sol.rotateMatrix(matrix);
  for (auto &m : matrix) {
    for (auto &x : m) {
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}