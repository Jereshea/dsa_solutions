/******************************************************************************

Print the matrix in spiral manner

Given an M * N matrix, print the elements in a clockwise spiral manner.



Return an array with the elements in the order of their appearance when printed
in a spiral manner.


Example 1

Input: matrix = [[1, 2, 3], [4 ,5 ,6], [7, 8, 9]]

Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]

Explanation:

The elements in the spiral order are 1, 2, 3 -> 6, 9 -> 8, 7 -> 4, 5

Example 2

Input: matrix = [[1, 2, 3, 4], [5, 6, 7, 8]]

Output: [1, 2, 3, 4, 8, 7, 6, 5]

Explanation:

The elements in the spiral order are 1, 2, 3, 4 -> 8, 7, 6, 5
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> result;
    if (matrix.empty()) {
      return result;
    }

    int left = 0;
    int right = matrix[0].size() - 1;
    int top = 0;
    int down = matrix.size() - 1;

    while (left <= right && top <= down) {
      // Traverse Left
      if (top <= down) {
        for (int i = left; i <= right; i++) {
          result.push_back(matrix[top][i]);
        }
        top++;
      }

      // Traverse Down
      if (left <= right) {
        for (int i = top; i <= down; i++) {
          result.push_back(matrix[i][right]);
        }
        right--;
      }

      // Traverse Right
      if (top <= down) {
        for (int i = right; i >= left; i--) {
          result.push_back(matrix[down][i]);
        }
        down--;
      }

      // Traverse Up
      if (left <= right) {
        for (int i = down; i >= top; i--) {
          result.push_back(matrix[i][left]);
        }
        left++;
      }
    }
    return result;
  }
};

int main() {
  cout << "Print the matrix in spiral manner" << endl;
  vector<vector<int>> matrix;
  matrix.push_back({1, 2, 3});
  matrix.push_back({4, 5, 6});
  matrix.push_back({7, 8, 9});
  // matrix.push_back({1, 2, 3, 4});
  // matrix.push_back({5, 6, 7, 8});
  Solution sol;
  vector<int> result = sol.spiralOrder(matrix);

  for (auto &m : matrix) {
    for (auto &x : m) {
      cout << x << " ";
    }
    cout << endl;
  }
  cout << endl << endl;
  for (auto &m : result) {
    cout << m << " ";
  }

  return 0;
}