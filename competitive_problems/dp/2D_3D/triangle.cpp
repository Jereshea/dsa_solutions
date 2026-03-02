/******************************************************************************
Triangle
Given a 2d integer array named triangle with n rows. Its first row has 1 element
and each succeeding row has one more element in it than the row above it.



Return the minimum falling path sum from the first row to the last.



Movement is allowed only to the bottom or bottom-right cell from the current
cell.


Example 1

Input: triangle = [[1], [1, 2], [1, 2, 4]]

Output: 3

Explanation:

One possible route can be:

Start at 1st row -> bottom -> bottom.

Example 2

Input: triangle = [[1], [4, 7], [4,10, 50], [-50, 5, 6, -100]]

Output: -42

Explanation:

One possible route can be:

Start at 1st row -> bottom-right -> bottom-right -> bottom-right
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
// Recursion
class Solution {
public:
    int minTriangleSum_rec(vector<vector<int>>& triangle, int cur_row, int
cur_col, int limit_row,int limit_col){ if(cur_row >= limit_row){ return 0;
        }

        if(cur_row == limit_row-1){
            return triangle[cur_row][cur_col];
        }

        int bottom=triangle[cur_row][cur_col]+minTriangleSum_rec(triangle,
cur_row+1, cur_col, limit_row,limit_col+1); int
bottom_right=triangle[cur_row][cur_col]+minTriangleSum_rec(triangle, cur_row+1,
cur_col+1, limit_row,limit_col+1);

        return min(bottom,bottom_right);
    }
    int minTriangleSum(vector<vector<int>>& triangle) {
        return minTriangleSum_rec(triangle, 0, 0, triangle.size(),1);
    }
};
*/

class Solution {
public:
  int minTriangleSum_rec(vector<vector<int>> &triangle, int cur_row,
                         int cur_col, int limit_row, vector<vector<int>> &dp) {
    if (cur_row >= limit_row) {
      return 0;
    }

    if (cur_row == limit_row - 1) {
      return triangle[cur_row][cur_col];
    }
    if (dp[cur_row][cur_col] != -1) {
      return dp[cur_row][cur_col];
    }

    int bottom =
        triangle[cur_row][cur_col] +
        minTriangleSum_rec(triangle, cur_row + 1, cur_col, limit_row, dp);
    int bottom_right =
        triangle[cur_row][cur_col] +
        minTriangleSum_rec(triangle, cur_row + 1, cur_col + 1, limit_row, dp);

    return dp[cur_row][cur_col] = min(bottom, bottom_right);
  }
  int minTriangleSum(vector<vector<int>> &triangle) {
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
    return minTriangleSum_rec(triangle, 0, 0, triangle.size(), dp);
  }
};

int main() {
  std::cout << "Triangle" << endl;
  vector<vector<int>> triangle = {{1}, {4, 7}, {4, 10, 50}, {-50, 5, 6, -100}};
  Solution sol;
  cout << sol.minTriangleSum(triangle);
  return 0;
}