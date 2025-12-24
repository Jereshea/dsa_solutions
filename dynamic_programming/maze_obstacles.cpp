/******************************************************************************
Unique Paths II

Problem statement
Given a ‘N’ * ’M’ maze with obstacles, count and return the number of unique
paths to reach the right-bottom cell from the top-left cell. A cell in the given
maze has a value '-1' if it is a blockage or dead-end, else 0. From a given
cell, we are allowed to move to cells (i+1, j) and (i, j+1) only. Since the
answer can be large, print it modulo 10^9 + 7.

For Example :
Consider the maze below :
0 0 0
0 -1 0
0 0 0

There are two ways to reach the bottom left corner -

(1, 1) -> (1, 2) -> (1, 3) -> (2, 3) -> (3, 3)
(1, 1) -> (2, 1) -> (3, 1) -> (3, 2) -> (3, 3)

Hence the answer for the above test case is 2.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
1 <= N,M <= 200

Note: It is guaranteed that the top-left cell does not have an obstacle.

Time Limit: 1 sec
Sample Input 1 :
2
2 2
0 0
0 0
3 3
0 0 0
0 -1 0
0 0 0
Sample Output 1 :
2
2
Explanation For Sample Output 1 :
For the first test case, there are two possible paths to reach (2, 2) from (1,
1) : (1, 1) -> (1, 2) -> (2, 2) (1, 1) -> (2, 1) -> (2, 2)

For the second test case, there are two ways to reach the bottom left corner -
(1, 1) -> (1, 2) -> (1, 3) -> (2, 3) -> (3, 3)
(1, 1) -> (2, 1) -> (3, 1) -> (3, 2) -> (3, 3)
Sample Input 2 :
1
2 2
0 -1
-1  0
Sample Output 2 :
0


*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
/*
int find_unique_path(int m, int n, vector<vector<int>> &mat, vector<vector<int>>
&unique_path){

    if(m<0 || n<0){
        return 0;
    }

    if(mat[m][n]!=0){
        return 0;
    }

    if((m==0 && n==0) && mat[m][n]==0){
        return 1;
    }


    if(unique_path[m][n]!=-1){
        return unique_path[m][n];
    }
    int left=find_unique_path(m, n-1, mat, unique_path); // backtracing so,right
will be n-1 int up=find_unique_path(m-1, n, mat, unique_path); // backtracing
so,down will be m-1 unique_path[m][n]=(left+up) % MOD; return
(unique_path[m][n]);
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>> unique_path(n, vector<int>(m, -1));
    return find_unique_path(n-1,m-1, mat, unique_path);
}

*/

int find_unique_path_tabulation(int m, int n, vector<vector<int>> &mat,
                                vector<vector<int>> &unique_path) {

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {

      if (i == 0 && j == 0 && mat[i][j] == 0) {
        unique_path[i][j] = 1;
        continue;
      }
      if (mat[i][j] == -1) {
        unique_path[i][j] = 0;
        continue;
      }
      int left = 0;
      int up = 0;
      if (j > 0) {
        left = unique_path[i][j - 1]; // backtracing so,right will be n-1
      }
      if (i > 0) {
        up = unique_path[i - 1][j]; // backtracing so,down will be m-1
      }
      unique_path[i][j] = (left + up) % MOD;
    }
  }

  return (unique_path[m - 1][n - 1]);
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
  // Write your code here
  vector<vector<int>> unique_path(n, vector<int>(m, 0));
  return find_unique_path_tabulation(n, m, mat, unique_path);
}

int main() {
  cout << "Unique Path" << endl;
  int m = 3; // col
  int n = 3; // row

  vector<vector<int>> mat = {{0, 0, 0}, {0, -1, 0}, {0, 0, 0}};
  cout << mazeObstacles(n, m, mat);

  return 0;
}