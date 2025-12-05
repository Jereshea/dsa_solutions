/******************************************************************************

DFS (Graph Traversal)

In BFS Graph traversal, we first have to print all the sub nodes of the current
node ie) we don't concentrate on its depth first. In DFS, if we have 3
neighbors, we have print the entire depth of the 1st neighbor, and only after
the completion we move to the next neightbor.


You are given an undirected and disconnected graph G(V.E) having V vertices from
0 to V-1 and E edges. Your task is to print its DFS traversal starting from the
0th vertex.

here nodes = 5; edges = 6
0 ----- 1 ------- 2
|\                |
| \              |
4----------------3

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int &vertex, unordered_map<int, set<int>> &adjacency_list,
         unordered_map<int, bool> &visited_node, vector<int> &ans) {

  visited_node[node] = 1;
  ans.push_back(node);

  for (auto &m : adjacency_list[node]) {
    if (!visited_node[m])
      dfs(m, vertex, adjacency_list, visited_node, ans);
  }
}
vector<int> depth_first_search(int vertex, vector<pair<int, int>> edges) {
  unordered_map<int, set<int>> adjacency_list;
  unordered_map<int, bool> visited_node;
  vector<int> ans;

  for (int i = 0; i < edges.size(); i++) {
    adjacency_list[edges[i].first].insert(edges[i].second);
    adjacency_list[edges[i].second].insert(edges[i].first);
  }

  // Initialize visited_node
  for (int i = 0; i < vertex; i++) {
    visited_node[i] = false;
  }

  // DFS
  // As the graph is a disconnected graph, we should make sure that we traverse
  // all the elements from 0 to V-1
  for (int i = 0; i < vertex; i++) {
    if (!visited_node[i]) {
      dfs(i, vertex, adjacency_list, visited_node, ans);
    }
  }
  return ans;
}
int main() {
  cout << "Graph" << endl;
  int vertex;
  cout << "Enter the value of vertex: " << endl;
  cin >> vertex;
  int edges_count;
  cout << "Enter the value of Edges: " << endl;
  cin >> edges_count;
  vector<pair<int, int>> edges;
  int u, v;
  for (int i = 0; i < edges_count; i++) {
    cout << "Enter the node (u) and its connected node (v)" << endl;
    cin >> u >> v;
    edges.push_back({u, v});
  }
  vector<int> result = depth_first_search(vertex, edges);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}
