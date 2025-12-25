/******************************************************************************

Triangle

Problem statement
You are given a triangular array/list 'TRIANGLE'. Your task is to return the
minimum path sum to reach from the top to the bottom row.

The triangle array will have N rows and the i-th row, where 0 <= i < N will have
i + 1 elements.

You can move only to the adjacent number of row below each step. For example, if
you are at index j in row i, then you can move to i or i + 1 index in row j + 1
in each step.

For Example :
If the array given is 'TRIANGLE' = [[1], [2,3], [3,6,7], [8,9,6,1]] the triangle
array will look like:

1
2,3
3,6,7
8,9,6,10

For the given triangle array the minimum sum path would be 1->2->3->8. Hence the
answer would be 14.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
// Recursion
int triangle_min(vector<vector<int>> &triangle, int total_row, int curr_row, int
curr_col){ if(curr_row==total_row-1){ return triangle[curr_row][curr_col];
    }

    if(curr_col >= triangle[curr_row].size()){
        return INT_MAX;
    }

    if(curr_col <0){
        return INT_MAX;
    }

    int right=triangle[curr_row][curr_col]+triangle_min(triangle, total_row,
curr_row+1, curr_col); int
down_right=triangle[curr_row][curr_col]+triangle_min(triangle, total_row,
curr_row+1, curr_col+1);

    return min(right, down_right);

}
*/

/*
// Memoization
int triangle_min_memoization(vector<vector<int>> &triangle, int total_row, int
curr_row, int curr_col, vector<vector<int>> &dp_array){
    if(curr_row==total_row-1){
        return triangle[curr_row][curr_col];
    }

    if(curr_col >= triangle[curr_row].size()){
        return INT_MAX;
    }

    if(curr_col <0){
        return INT_MAX;
    }

    if(dp_array[curr_row][curr_col]!=-1){
        return dp_array[curr_row][curr_col];
    }
    int right=triangle[curr_row][curr_col]+triangle_min_memoization(triangle,
total_row, curr_row+1, curr_col, dp_array); int
down_right=triangle[curr_row][curr_col]+triangle_min_memoization(triangle,
total_row, curr_row+1, curr_col+1, dp_array);
    dp_array[curr_row][curr_col]=min(right, down_right);
    return dp_array[curr_row][curr_col];

}
*/

// Tabulation
int triangle_min_tabulation(vector<vector<int>> &triangle, int total_row,
                            int curr_row, int curr_col,
                            vector<vector<int>> &dp_array) {
  for (int i = 0; i < triangle[total_row - 1].size(); i++) {
    dp_array[total_row - 1][i] = triangle[total_row - 1][i];
  }

  for (int i = total_row - 2; i >= 0; i--) {
    for (int j = triangle[i].size() - 1; j >= 0; j--) {
      int right = triangle[i][j] + dp_array[i + 1][j];
      int down_right = triangle[i][j] + dp_array[i + 1][j + 1];
      dp_array[i][j] = min(right, down_right);
    }
  }

  return dp_array[0][0];
}

int main() {
  cout << "Triangle Minimum Path" << endl;
  vector<vector<int>> triangle;
  triangle.push_back({1});
  triangle.push_back({2, 3});
  triangle.push_back({3, 6, 7});
  triangle.push_back({8, 9, 6, 10});
  int total_row = triangle.size();
  // Recursion
  // cout<<triangle_min(triangle, total_row, 0, 0);
  // dp_memoization
  // vector<vector<int>> dp_array(total_row, vector<int>(total_row, -1));
  // cout<<triangle_min_memoization(triangle, total_row, 0, 0,dp_array);
  // Tabulation
  vector<vector<int>> dp_array(total_row, vector<int>(total_row, INT_MAX));
  cout << triangle_min_tabulation(triangle, total_row, 0, 0, dp_array);

  return 0;
}