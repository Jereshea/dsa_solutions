/***********
Shortest Distance in a Binary Maze

Given an n x m matrix grid where each cell contains either 0 or 1, determine the
shortest distance between a source cell and a destination cell. You can move to
an adjacent cell (up, down, left, or right) if that adjacent cell has a value
of 1. The path can only be created out of cells containing 1. If the destination
cell is not reachable from the source cell, return -1.


Example 1

Input: grid = [[1, 1, 1, 1],[1, 1, 0, 1],[1, 1, 1, 1],[1, 1, 0, 0],[1, 0, 0,
1]], source = [0, 1], destination = [2, 2]

Output: 3

Explanation: The shortest path from (0, 1) to (2, 2) is:

Move down to (1, 1)

Move down to (2, 1)

Move right to (2, 2)

Thus, the shortest distance is 3

Example 2

Input: grid = [[1, 1, 1, 1, 1],[1, 1, 1, 1, 1],[1, 1, 1, 1, 0],[1, 0, 1, 0, 1]],
source = [0, 0], destination = [3, 4]

Output: -1

Explanation:

Since, there is no path possible between the source cell and the destination
cell, hence we return -1.


*************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                   pair<int, int> destination) {

    // BFS Traversal
    int row = grid.size();
    int col = grid[0].size();
    queue<pair<int, pair<int, int>>> q_row_col_dist;
    pair<int, pair<int, int>> p = make_pair(0, source);
    q_row_col_dist.push(p);
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));

    vector<int> possible_rows = {-1, 1, 0, 0};
    vector<int> possible_cols = {0, 0, -1, 1};
    while (!q_row_col_dist.empty()) {
      int dist = q_row_col_dist.front().first;
      int cur_row = q_row_col_dist.front().second.first;
      int curr_col = q_row_col_dist.front().second.second;
      q_row_col_dist.pop();

      for (int i = 0; i < 4; i++) {
        int new_row = cur_row + possible_rows[i];
        int new_col = curr_col + possible_cols[i];
        if (new_row >= 0 && new_row < row && new_col >= 0 && new_col < col &&
            grid[new_row][new_col] == 1 && visited[new_row][new_col] == 0) {
          visited[new_row][new_col] = 1;
          pair<int, int> p = make_pair(new_row, new_col);

          if (p == destination) {
            return dist + 1;
            break;
          }

          pair<int, pair<int, int>> p1 = make_pair(dist + 1, p);
          q_row_col_dist.push(p1);
        }
      }
    }
    return -1;
  }
};

int main() {
  // your code goes here
  cout << "Shortest Distance in a Binary Maze" << endl;
  vector<vector<int>> grid = {
      {1, 1, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}, {1, 0, 0, 1}};
  pair<int, int> source = make_pair(0, 1);
  pair<int, int> destination = make_pair(2, 2);

  // 	vector<vector<int>> grid = {{1, 1, 1, 1, 1},{1, 1, 1, 1, 1},{1, 1, 1, 1,
  // 0},{1, 0, 1, 0, 1}}; 	pair<int,int>source = make_pair(0, 0); 	pair<int,int>
  // destination = make_pair(3, 4);
  Solution sol;
  cout << sol.shortestPath(grid, source, destination);
}
