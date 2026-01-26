/************************
Connected Components

Given a undirected Graph consisting of V vertices numbered from 0 to V-1 and E
edges. The ith edge is represented by [ai,bi], denoting a edge between vertex ai
and bi. We say two vertices u and v belong to a same component if there is a
path from u to v or v to u. Find the number of connected components in the
graph.



A connected component is a subgraph of a graph in which there exists a path
between any two vertices, and no vertex of the subgraph shares an edge with a
vertex outside of the subgraph.


Example 1



Input: V=4, edges=[[0,1],[1,2]]

Output: 2

Explanation: Vertices {0,1,2} forms the first component and vertex 3 forms the
second component.

Example 2

Input: V = 7, edges = [[0, 1], [1, 2], [2, 3], [4, 5]]

Output: 3

Explanation:

The edges [0, 1], [1, 2], [2, 3] form a connected component with vertices {0, 1,
2, 3}.

The edge [4, 5] forms another connected component with vertices {4, 5}.

Therefore, the graph has 3 connected components: {0, 1, 2, 3}, {4, 5}, and the
isolated vertices {6} (vertices 6 and any other unconnected vertices).

***************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void traversal(vector<vector<int>> &adj_list, vector<int> &visited,
                 int node) {
    queue<int> q;
    visited[node] = 1;

    q.push(node);
    while (!q.empty()) {
      int front_node = q.front();
      q.pop();

      for (int i = 0; i < adj_list[front_node].size(); i++) {
        if (visited[adj_list[front_node][i]] == 0) {
          visited[adj_list[front_node][i]] = 1;
          q.push(adj_list[front_node][i]);
        }
      }
    }
  }
  int findNumberOfComponent(int V, vector<vector<int>> &edges) {
    int components = 0;
    vector<int> visited(V, 0);
    vector<vector<int>> adj_list(V);

    // Create Adj List
    for (int i = 0; i < edges.size(); i++) {
      int u = edges[i][0];
      int v = edges[i][1];

      adj_list[u].push_back(v);
      adj_list[v].push_back(u);
    }

    // BFS Traversal
    for (int i = 0; i < V; i++) {
      if (visited[i] == 0) {
        components += 1;
        traversal(adj_list, visited, i);
      }
    }
    return components;
  }
};

int main() {
  // your code goes here
  cout << "Connected Components" << endl;
  // 	int V=4;
  //     vector<vector<int>> edges={{0,1},{1,2}};
  int V = 7;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {4, 5}};
  Solution sol;
  cout << sol.findNumberOfComponent(V, edges);
}
