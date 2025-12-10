/******************************************************************************
Bridges in a graph

   0
  / \
 /   \
2 --- 1
      |
      3
      |
      4



Mapping
From  To
0	  1
0	  2
2	  1
1	  3
3	  4

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void bridges_find(int &timer, int src, int parent, vector<vector<int>> &adj,
                  vector<bool> &visited_nodes, vector<int> &traversal_time,
                  vector<int> &low_time_to_traverse,
                  vector<vector<int>> &result) {

  visited_nodes[src] = true;
  traversal_time[src] = low_time_to_traverse[src] = timer;

  // Traverse the adj node (DFS)
  for (auto &m : adj[src]) {

    // Case:1
    if (m == parent) {
      continue;
    }

    // Case:2
    if (!visited_nodes[m]) {
      timer++;
      bridges_find(timer, m, src, adj, visited_nodes, traversal_time,
                   low_time_to_traverse, result);

      low_time_to_traverse[src] =
          min(low_time_to_traverse[src], low_time_to_traverse[m]);

      if (low_time_to_traverse[m] > traversal_time[src]) {
        result.push_back({m, src});
      }
    }

    // Case:3
    else {
      low_time_to_traverse[src] =
          min(low_time_to_traverse[src], low_time_to_traverse[m]);
    }
  }
}
void bridges_in_graph(int src, int vertex, vector<vector<int>> edges) {

  // Create Adjacency list to to DFS
  vector<vector<int>> adj(vertex);
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // Track visited_nodes
  vector<bool> visited_nodes(vertex, false);
  // Algorithm
  // STEP1: Create traversal to maintain the traversal time
  vector<int> traversal_time(vertex, -1);

  // STEP2: Create low_time_to_traverse to get the lowest path from the adjacent
  // nodes except the parent
  vector<int> low_time_to_traverse(vertex, -1);

  // Result
  vector<vector<int>> result;
  int parent = -1;
  int timer = 0;
  bridges_find(timer, src, parent, adj, visited_nodes, traversal_time,
               low_time_to_traverse, result);

  // Print the result
  for (int i = 0; i < result.size(); i++) {
    for (auto &m : result[i]) {
      cout << m << " ";
    }
    cout << endl;
  }
}
int main() {
  cout << "Bridges in a graph" << endl;
  int vertex = 5;
  vector<vector<int>> edges;
  edges.push_back({0, 1});
  edges.push_back({0, 2});
  edges.push_back({2, 1});
  edges.push_back({1, 3});
  edges.push_back({3, 4});
  int src = 0;
  bridges_in_graph(src, vertex, edges);

  return 0;
}