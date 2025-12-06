/******************************************************************************

Cycle Detection in a Graph

Approach:

If we have a graph, it is a undirected graph. So when we maintain a visited[]
matrix to mark all the visited nodes, if the node is already visited, then it
has to be the curr nodes parent.

On that note, in the adjacency_list, if a node is already visited but it not the
parent, then the graph has a cycle.

0 -- 1       2 ---- 3
             |      |
             |      |
             5 ---- 4 ----6

Mapping:
0 1
2 3
3 4
4 5
4 6

Adjacency List
0   1
1   0
2   3, 5
3   2, 4
4   3, 5, 6
5   2, 4
6   4
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

bool dfs_traversal(int i, unordered_map<int, list<int>> &adjacency_matrix,
                   unordered_map<int, bool> &visited,
                   unordered_map<int, int> &parent) {

  visited[i] = true;

  for (auto &m : adjacency_matrix[i]) {
    if (visited[m] && (m != parent[i])) {
      // cout<<"The graph has cycle";
      return true;
    } else if (!visited[m]) {
      parent[m] = i;
      if (dfs_traversal(m, adjacency_matrix, visited, parent)) {
        return true;
      }
    }
  }

  return false;
}
bool cycle_detection_dfs(int vertex, vector<vector<int>> &edges) {

  unordered_map<int, list<int>> adjacency_matrix;
  unordered_map<int, bool> visited;
  unordered_map<int, int> parent;

  // Create the adjacency list
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];

    adjacency_matrix[u].push_back(v);
    adjacency_matrix[v].push_back(u);
  }

  // Initially create visited with false
  for (int i = 0; i < vertex; i++) {
    visited[i] = false;
  }

  // To make all the disconnected graphs are included
  for (int i = 0; i < vertex; i++) {
    if (!visited[i]) {
      parent[i] = -1;
      if (dfs_traversal(i, adjacency_matrix, visited, parent)) {
        return true;
      }
    }
  }
  return false;
}
int main() {
  int vertex = 7;
  vector<vector<int>> edges;
  edges.push_back({0, 1});
  edges.push_back({2, 3});
  edges.push_back({3, 4});
  edges.push_back({4, 5});
  edges.push_back({5, 2});
  edges.push_back({4, 6});

  if (cycle_detection_dfs(vertex, edges)) {
    cout << "The graph has a cycle" << endl;
  } else {
    cout << "No cycle is present" << endl;
  }
  return 0;
}