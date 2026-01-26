/******************************************************************************

Flood fill algorithm

An image is represented by a 2-D array of integers, each integer representing
the pixel value of the image. Given a coordinate (sr, sc) representing the
starting pixel (row and column) of the flood fill, and a pixel value newColor,
"flood fill" the image.

To perform a flood fill, consider the starting pixel, plus any pixels connected
4-directionally to the starting pixel of the same colour as the starting pixel,
plus any pixels connected 4-directionally to those pixels (also with the same
colour as the starting pixel), and so on. Replace the colour of all of the
aforementioned pixels with the newColor.

Example 1
Input: image = [ [1, 1, 1], [1, 1, 0], [1, 0, 1] ], sr = 1, sc = 1, newColor = 2

Output: [ [2, 2, 2], [2, 2, 0], [2, 0, 1] ]

Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e.,
the red pixel), all pixels connected by a path of the same color as the starting
pixel (i.e., the blue pixels) are colored with the new color.

Note the bottom corner is not colored 2, because it is not 4-directionally
connected to the starting pixel.

Example 2

Input: image = [ [0, 1, 0], [1, 1, 0], [0, 0, 1] ], sr = 2, sc = 2, newColor = 3

Output: [ [0, 1, 0], [1, 1, 0], [0, 0, 3] ]

Explanation: Starting from the pixel at position (2, 2) (i.e., the blue pixel),
we flood fill all adjacent pixels that have the same color as the starting
pixel. In this case, only the pixel at position (2, 2) itself is of the same
color. So, only that pixel gets colored with the new color, resulting in the
updated image.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void bfs_traversal(vector<vector<int>> &image, int sr, int sc, int newColor,
                     vector<vector<int>> &visited) {
    queue<pair<int, int>> q;
    q.push(make_pair(sr, sc));
    image[sr][sc] = newColor;
    visited[sr][sc] = 1;

    vector<int> possible_rows = {-1, 1, 0, 0};
    vector<int> possible_cols = {0, 0, -1, 1};
    while (!q.empty()) {
      int row = q.front().first;
      int col = q.front().second;

      q.pop();
      for (int i = 0; i < 4; i++) {
        int new_row = row + possible_rows[i];
        int new_col = col + possible_cols[i];

        if (new_row >= 0 && new_row < image.size() && new_col >= 0 &&
            new_col < image[0].size() && image[new_row][new_col] == 1 &&
            visited[new_row][new_col] == -1) {
          visited[new_row][new_col] = 1;
          q.push(make_pair(new_row, new_col));
          image[new_row][new_col] = newColor;
        }
      }
    }
  }
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int newColor) {

    vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), -1));

    bfs_traversal(image, sr, sc, newColor, visited);
    return image;
  }
};

int main() {
  cout << "Flood fill algorithm" << endl;
  vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
  int sr = 1;
  int sc = 1;
  int newColor = 2;
  // vector<vector<int>> image = {{0, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  // int sr = 2;
  // int sc = 2;
  // int newColor = 3;
  Solution sol;
  vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);
  for (auto &m : result) {
    for (auto &x : m) {
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}