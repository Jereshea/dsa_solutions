/******************************************************************************

Ninja and his Friends

Ninja has a grid of size R x C, where each cell contains some chocolates. He has
two friends: Alice and Bob, and wants to collect as many chocolates as possible
using their help.



Alice starts at the top-left cell (0, 0)
Bob starts at the top-right cell (0, C - 1)
Both can only move to the next row, and from position (i, j), they can move to:
(i + 1, j)
(i + 1, j - 1)
(i + 1, j + 1)


Both must remain within the grid bounds.
Each collects all chocolates in their current cell.
If both land on the same cell, the chocolates are only counted once.


Return the maximum number of chocolates Ninja can collect using his two friends.


Example 1

Input: grid = [[2, 3, 1, 2],[3, 4, 2, 2],[5, 6, 3, 5]]

Output: 21

Explanation:

Alice: (0,0) → (1,1) → (2,1) → chocolates = 2 + 4 + 6 = 12
Bob:  (0,3) → (1,3) → (2,3) → chocolates = 2 + 2 + 5 = 9
Total = 12 + 9 = 21


Example 2

Input: grid = [[1, 2],[3, 4]]

Output: 10

Explanation:

Alice: (0,0) → (1,0) → 1 + 3 = 4
Bob:  (0,1) → (1,1) → 2 + 4 = 6
But both can’t pick at same time (if they land same cell), so:
Best is (0,0)+(1,0)+(0,1)+(1,1) - overlap = 1+3+2+4 = 10
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
// Recursion
class Solution {
public:
    int maxChocolates_rec(vector<vector<int>>& g, int alice_row, int alice_col,
int bob_row, int bob_col, int row, int col){ if(alice_row >= row || alice_row <
0 || alice_col >= col || alice_col < 0 || bob_row >= row || bob_row < 0 ||
bob_col >= col || bob_col < 0){ return 0;
        }

        if(alice_row == row-1){
            if(alice_row==bob_row && alice_col==bob_col)
                return g[alice_row][alice_col];
            return g[alice_row][alice_col]+g[bob_row][bob_col];
        }


        int bottom_1=INT_MIN;
        int bottom_2=INT_MIN;
        int bottom_3=INT_MIN;

        int bottom_left_1=INT_MIN;
        int bottom_left_2=INT_MIN;
        int bottom_left_3=INT_MIN;

        int bottom_right_1=INT_MIN;
        int bottom_right_2=INT_MIN;
        int bottom_right_3=INT_MIN;

        if(alice_row == bob_row && alice_col == bob_col){
            bottom_1=g[alice_row][alice_col]+maxChocolates_rec(g,alice_row+1,
alice_col,bob_row+1,bob_col,row,col);
            bottom_2=g[alice_row][alice_col]+maxChocolates_rec(g,alice_row+1,
alice_col,bob_row+1,bob_col-1,row,col);
            bottom_3=g[alice_row][alice_col]+maxChocolates_rec(g,alice_row+1,
alice_col,bob_row+1,bob_col+1,row,col);


            bottom_left_1=g[alice_row][alice_col]+maxChocolates_rec(g,alice_row+1,
alice_col-1,bob_row+1,bob_col,row,col);
            bottom_left_2=g[alice_row][alice_col]+maxChocolates_rec(g,alice_row+1,
alice_col-1,bob_row+1,bob_col-1,row,col);
            bottom_left_3=g[alice_row][alice_col]+maxChocolates_rec(g,alice_row+1,
alice_col-1,bob_row+1,bob_col+1,row,col);

            bottom_right_1=g[alice_row][alice_col]+maxChocolates_rec(g,alice_row+1,
alice_col+1,bob_row+1,bob_col,row,col);
            bottom_right_2=g[alice_row][alice_col]+maxChocolates_rec(g,alice_row+1,
alice_col+1,bob_row+1,bob_col-1,row,col);
            bottom_right_3=g[alice_row][alice_col]+maxChocolates_rec(g,alice_row+1,
alice_col+1,bob_row+1,bob_col+1,row,col); }else{
            bottom_1=g[alice_row][alice_col]+g[bob_row][bob_col]+maxChocolates_rec(g,alice_row+1,
alice_col,bob_row+1,bob_col,row,col);
            bottom_2=g[alice_row][alice_col]+g[bob_row][bob_col]+maxChocolates_rec(g,alice_row+1,
alice_col,bob_row+1,bob_col-1,row,col);
            bottom_3=g[alice_row][alice_col]+g[bob_row][bob_col]+maxChocolates_rec(g,alice_row+1,
alice_col,bob_row+1,bob_col+1,row,col);


            bottom_left_1=g[alice_row][alice_col]+g[bob_row][bob_col]+maxChocolates_rec(g,alice_row+1,
alice_col-1,bob_row+1,bob_col,row,col);
            bottom_left_2=g[alice_row][alice_col]+g[bob_row][bob_col]+maxChocolates_rec(g,alice_row+1,
alice_col-1,bob_row+1,bob_col-1,row,col);
            bottom_left_3=g[alice_row][alice_col]+g[bob_row][bob_col]+maxChocolates_rec(g,alice_row+1,
alice_col-1,bob_row+1,bob_col+1,row,col);

            bottom_right_1=g[alice_row][alice_col]+g[bob_row][bob_col]+maxChocolates_rec(g,alice_row+1,
alice_col+1,bob_row+1,bob_col,row,col);
            bottom_right_2=g[alice_row][alice_col]+g[bob_row][bob_col]+maxChocolates_rec(g,alice_row+1,
alice_col+1,bob_row+1,bob_col-1,row,col);
            bottom_right_3=g[alice_row][alice_col]+g[bob_row][bob_col]+maxChocolates_rec(g,alice_row+1,
alice_col+1,bob_row+1,bob_col+1,row,col);
        }

        return
max(bottom_1,max(bottom_2,max(bottom_3,max(bottom_left_1,max(bottom_left_2,max(bottom_left_2,max(bottom_left_3,max(bottom_right_1,max(bottom_right_2,bottom_right_3)))))))));

    }
    int maxChocolates(vector<vector<int>>& g) {
        // Your code goes here
        int row=g.size();
        int col=g[0].size();
        return maxChocolates_rec(g, 0,0,0,col-1,row,col);
    }
};
*/

class Solution {
public:
  int maxChocolates_rec(vector<vector<int>> &g, int alice_row, int alice_col,
                        int bob_row, int bob_col, int row, int col,
                        vector<vector<vector<int>>> &dp) {
    if (alice_row >= row || alice_row < 0 || alice_col >= col ||
        alice_col < 0 || bob_row >= row || bob_row < 0 || bob_col >= col ||
        bob_col < 0) {
      return 0;
    }

    if (alice_row == row - 1) {
      if (alice_row == bob_row && alice_col == bob_col)
        return g[alice_row][alice_col];
      return g[alice_row][alice_col] + g[bob_row][bob_col];
    }

    if (dp[alice_row][alice_col][bob_col] != -1) {
      return dp[alice_row][alice_col][bob_col];
    }
    int bottom_1 = INT_MIN;
    int bottom_2 = INT_MIN;
    int bottom_3 = INT_MIN;

    int bottom_left_1 = INT_MIN;
    int bottom_left_2 = INT_MIN;
    int bottom_left_3 = INT_MIN;

    int bottom_right_1 = INT_MIN;
    int bottom_right_2 = INT_MIN;
    int bottom_right_3 = INT_MIN;

    if (alice_row == bob_row && alice_col == bob_col) {
      bottom_1 = g[alice_row][alice_col] +
                 maxChocolates_rec(g, alice_row + 1, alice_col, bob_row + 1,
                                   bob_col, row, col, dp);
      bottom_2 = g[alice_row][alice_col] +
                 maxChocolates_rec(g, alice_row + 1, alice_col, bob_row + 1,
                                   bob_col - 1, row, col, dp);
      bottom_3 = g[alice_row][alice_col] +
                 maxChocolates_rec(g, alice_row + 1, alice_col, bob_row + 1,
                                   bob_col + 1, row, col, dp);

      bottom_left_1 = g[alice_row][alice_col] +
                      maxChocolates_rec(g, alice_row + 1, alice_col - 1,
                                        bob_row + 1, bob_col, row, col, dp);
      bottom_left_2 = g[alice_row][alice_col] +
                      maxChocolates_rec(g, alice_row + 1, alice_col - 1,
                                        bob_row + 1, bob_col - 1, row, col, dp);
      bottom_left_3 = g[alice_row][alice_col] +
                      maxChocolates_rec(g, alice_row + 1, alice_col - 1,
                                        bob_row + 1, bob_col + 1, row, col, dp);

      bottom_right_1 = g[alice_row][alice_col] +
                       maxChocolates_rec(g, alice_row + 1, alice_col + 1,
                                         bob_row + 1, bob_col, row, col, dp);
      bottom_right_2 =
          g[alice_row][alice_col] +
          maxChocolates_rec(g, alice_row + 1, alice_col + 1, bob_row + 1,
                            bob_col - 1, row, col, dp);
      bottom_right_3 =
          g[alice_row][alice_col] +
          maxChocolates_rec(g, alice_row + 1, alice_col + 1, bob_row + 1,
                            bob_col + 1, row, col, dp);
    } else {
      bottom_1 = g[alice_row][alice_col] + g[bob_row][bob_col] +
                 maxChocolates_rec(g, alice_row + 1, alice_col, bob_row + 1,
                                   bob_col, row, col, dp);
      bottom_2 = g[alice_row][alice_col] + g[bob_row][bob_col] +
                 maxChocolates_rec(g, alice_row + 1, alice_col, bob_row + 1,
                                   bob_col - 1, row, col, dp);
      bottom_3 = g[alice_row][alice_col] + g[bob_row][bob_col] +
                 maxChocolates_rec(g, alice_row + 1, alice_col, bob_row + 1,
                                   bob_col + 1, row, col, dp);

      bottom_left_1 = g[alice_row][alice_col] + g[bob_row][bob_col] +
                      maxChocolates_rec(g, alice_row + 1, alice_col - 1,
                                        bob_row + 1, bob_col, row, col, dp);
      bottom_left_2 = g[alice_row][alice_col] + g[bob_row][bob_col] +
                      maxChocolates_rec(g, alice_row + 1, alice_col - 1,
                                        bob_row + 1, bob_col - 1, row, col, dp);
      bottom_left_3 = g[alice_row][alice_col] + g[bob_row][bob_col] +
                      maxChocolates_rec(g, alice_row + 1, alice_col - 1,
                                        bob_row + 1, bob_col + 1, row, col, dp);

      bottom_right_1 = g[alice_row][alice_col] + g[bob_row][bob_col] +
                       maxChocolates_rec(g, alice_row + 1, alice_col + 1,
                                         bob_row + 1, bob_col, row, col, dp);
      bottom_right_2 =
          g[alice_row][alice_col] + g[bob_row][bob_col] +
          maxChocolates_rec(g, alice_row + 1, alice_col + 1, bob_row + 1,
                            bob_col - 1, row, col, dp);
      bottom_right_3 =
          g[alice_row][alice_col] + g[bob_row][bob_col] +
          maxChocolates_rec(g, alice_row + 1, alice_col + 1, bob_row + 1,
                            bob_col + 1, row, col, dp);
    }

    return dp[alice_row][alice_col][bob_col] =
               max(bottom_1,
                   max(bottom_2,
                       max(bottom_3,
                           max(bottom_left_1,
                               max(bottom_left_2,
                                   max(bottom_left_2,
                                       max(bottom_left_3,
                                           max(bottom_right_1,
                                               max(bottom_right_2,
                                                   bottom_right_3)))))))));
  }
  int maxChocolates(vector<vector<int>> &g) {
    // Your code goes here
    int row = g.size();
    int col = g[0].size();
    vector<vector<vector<int>>> dp(
        row, vector<vector<int>>(col, vector<int>(col, -1)));
    return maxChocolates_rec(g, 0, 0, 0, col - 1, row, col, dp);
  }
};

int main() {
  cout << "Ninja and his Friends" << endl;
  vector<vector<int>> g = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
  Solution sol;
  cout << sol.maxChocolates(g);
  return 0;
}