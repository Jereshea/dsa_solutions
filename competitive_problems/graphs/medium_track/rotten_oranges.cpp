/************************
Rotten Oranges

Given an n x m grid, where each cell has the following values :

2 - represents a rotten orange

1 - represents a Fresh orange

0 - represents an Empty Cell

Every minute, if a fresh orange is adjacent to a rotten orange in 4-direction (
upward, downwards, right, and left ) it becomes rotten.



Return the minimum number of minutes required such that none of the cells has a
Fresh Orange. If it's not possible, return -1.


Example 1

Input: grid = [ [2, 1, 1] , [0, 1, 1] , [1, 0, 1] ]

Output: -1

Explanation: Orange at (3,0) cannot be rotten.

Example 2

Input: grid = [ [2,1,1] , [1,1,0] , [0,1,1] ]

Output: 4
***************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int traversal(vector<vector<int>> &grid, vector<vector<int>> &visited,
                queue<pair<int, pair<int, int>>> &q) {
    int total_time = 0;
    while (!q.empty()) {
      int row = q.front().first;
      int col = q.front().second.first;
      int curr_time = q.front().second.second;
      q.pop();

      // Traversing in the 4 possible directions (Up, Down, Left, Right)
      vector<int> possible_row = {-1, 1, 0, 0};
      vector<int> possible_col = {0, 0, -1, 1};
      for (int i = 0; i < 4; i++) {
        int new_row = row + possible_row[i];
        int new_col = col + possible_col[i];
        if (new_row >= 0 && new_row < grid.size() && new_col >= 0 &&
            new_col < grid[0].size() && grid[new_row][new_col] == 1 &&
            visited[new_row][new_col] == -1) {
          grid[new_row][new_col] = 2;
          visited[new_row][new_col] = 2;
          q.push(make_pair(new_row, make_pair(new_col, curr_time + 1)));
          total_time = max(total_time, curr_time + 1);
        }
      }
    }
    return total_time;
  }

  int orangesRotting(vector<vector<int>> &grid) {
    queue<pair<int, pair<int, int>>> q;

    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), -1));
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == 2) {
          visited[i][j] = 2;
          pair<int, pair<int, int>> p = make_pair(i, make_pair(j, 0));
          q.push(p);
        }
      }
    }
    int result = traversal(grid, visited, q);

    // Check if all the fresh oranges are rotten
    for (auto &x : grid) {
      for (auto &m : x) {
        if (m == 1) {
          return -1;
        }
      }
    }

    return result;
  }
};

int main() {
  // your code goes here
  cout << "Rotten Oranges" << endl;
  vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  // vector<vector<int>> grid = {{2, 1, 1} , {0, 1, 1} , {1, 0, 1}};
  Solution sol;
  cout << sol.orangesRotting(grid);
  return 0;
}
