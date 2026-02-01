/*************
Given a binary grid of N x M. Find the distance of the nearest 1 in the grid for
each cell.



The distance is calculated as |i1 - i2| + |j1 - j2|, where i1, j1 are the row
number and column number of the current cell, and i2, j2 are the row number and
column number of the nearest cell having value 1.


Example 1



Input: grid = [ [0, 1, 1, 0], [1, 1, 0, 0], [0, 0, 1, 1] ]

Output: [ [1, 0, 0, 1], [0, 0, 1, 1], [1, 1, 0, 0] ]

Explanation: 0's at (0,0), (0,3), (1,2), (1,3), (2,0) and (2,1) are at a
distance of 1 from 1's at (0,1),(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.
*************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void bfs_traversal(vector<vector<int>> &distance, queue<pair<int, int>> &q,
                     int row, int col) {

    while (!q.empty()) {
      int front_node_row = q.front().first;
      int fron_node_col = q.front().second;
      q.pop();

      int min_dist = INT_MAX;

      // Adj cells
      vector<int> adj_rows = {-1, 1, 0, 0};
      vector<int> adj_cols = {0, 0, -1, 1};

      for (int i = 0; i < 4; i++) {
        int curr_row = adj_rows[i] + front_node_row;
        int curr_col = adj_cols[i] + fron_node_col;
        if (curr_row >= 0 && curr_row < row && curr_col >= 0 &&
            curr_col < col && distance[curr_row][curr_col] == -1) {
          distance[curr_row][curr_col] =
              distance[front_node_row][fron_node_col] + 1;
          pair<int, int> p = make_pair(curr_row, curr_col);
          q.push(p);
        }
      }
    }
  }
  vector<vector<int>> nearest(vector<vector<int>> grid) {
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<int>> distance(row, vector<int>(col, -1));
    queue<pair<int, int>> q;
    vector<pair<int, int>> cells_with_1;

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (grid[i][j] == 1) {
          distance[i][j] = 0;
          pair<int, int> p = make_pair(i, j);
          q.push(p);
        }
      }
    }

    bfs_traversal(distance, q, row, col);

    for (auto &m : distance) {
      for (auto &x : m) {
        cout << x << " ";
      }
      cout << endl;
    }

    return distance;
  }
};

int main() {
  // your code goes here
  vector<vector<int>> grid = {{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}};
  Solution sol;
  sol.nearest(grid);
}
