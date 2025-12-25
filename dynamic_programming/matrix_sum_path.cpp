/******************************************************************************

Maximum Path Sum in the matrix:

You have been given an N*M matrix filled with integer numbers, find the maximum
sum that can be obtained from a path starting from any cell in the first row to
any cell in the last row.

From a cell in a row, you can move to another cell directly below that row, or
diagonally below left or right. So from a particular cell (row, col), we can
move in three directions i.e.

Down: (row+1,col)
Down left diagonal: (row+1,col-1)
Down right diagonal: (row+1, col+1)

Input 1 :
2
4 4
1 2 10 4
100 3 2 1
1 1 20 2
1 2 2 1
3 3
10 2 3
3 7 2
8 1 5
Output 1 :
105
25
Explanation Of Input 1 :
In the first test case for the given matrix,

The maximum path sum will be 2->100->1->2, So the sum is 105(2+100+1+2).

In the second test case for the given matrix, the maximum path sum will be
10->7->8, So the sum is 25(10+7+8).
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
// Recursion
int maximum_path_find(vector<vector<int>> &matrix, int row, int col, int
matrix_row, int matrix_col){

    if (row >= matrix_row || row < 0) {
        return INT_MIN;
    }

    if (col >= matrix_col || col < 0) {
        return INT_MIN;
    }

    if (row == matrix_row - 1) {
        return matrix[row][col];
    }

    if (dp_array[row][col] != INT_MIN) {
        return dp_array[row][col];
    }

    int down=matrix[row][col]+maximum_path_find(matrix,row+1, col, matrix_row,
matrix_col); int
diangonally_left=matrix[row][col]+maximum_path_find(matrix,row+1, col-1,
matrix_row, matrix_col); int
diagonally_right=matrix[row][col]+maximum_path_find(matrix,row+1, col+1,
matrix_row, matrix_col);

    return max(down,max(diangonally_left,diagonally_right));
}
*/

int maximum_path_find(vector<vector<int>> &matrix, int row, int col,
                      int matrix_row, int matrix_col,
                      vector<vector<int>> &dp_array) {

  if (row >= matrix_row || row < 0) {
    return INT_MIN;
  }

  if (col >= matrix_col || col < 0) {
    return INT_MIN;
  }

  if (row == matrix_row - 1) {
    return matrix[row][col];
  }

  if (dp_array[row][col] != INT_MIN) {
    return dp_array[row][col];
  }

  int down =
      matrix[row][col] +
      maximum_path_find(matrix, row + 1, col, matrix_row, matrix_col, dp_array);
  int diangonally_left =
      matrix[row][col] + maximum_path_find(matrix, row + 1, col - 1, matrix_row,
                                           matrix_col, dp_array);
  int diagonally_right =
      matrix[row][col] + maximum_path_find(matrix, row + 1, col + 1, matrix_row,
                                           matrix_col, dp_array);

  return dp_array[row][col] =
             max(down, max(diangonally_left, diagonally_right));
}
void maximim_path_matrix(int m, int n, vector<vector<int>> &matrix) {
  int ans = INT_MIN;
  /*
  // Recursion
  for(int fixed_start=0;fixed_start < n;fixed_start++){
      int result=maximum_path_find(matrix, 0, fixed_start, m,n);
      ans=max(ans, result);
  }
  */
  vector<vector<int>> dp_array(m, vector<int>(n, INT_MIN));
  for (int fixed_start = 0; fixed_start < n; fixed_start++) {
    int result = maximum_path_find(matrix, 0, fixed_start, m, n, dp_array);
    ans = max(ans, result);
  }
  cout << ans;
}
int main() {
  cout << "Maximum Path Sum in the matrix" << endl;
  int m = 4;
  int n = 4;
  vector<vector<int>> matrix = {
      {1, 2, 10, 2}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
  maximim_path_matrix(m, n, matrix);

  return 0;
}