/******************************************************************************

Topological Sort (using DFS Ttaversal)

Topological Sort happens only in DAG (Directed Acyclic Graph).
It arranges nodes of a directed grpah into linear sequence where every node
appears before any node points to it.

0 ----> 1 ------> 4 ------> 5
        |         ^
        |         |
       \/         |
        2 ------->3

Mapping:
0   1
1   4
1   2
2   3
3   4
4   5
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void bfs_traversal(queue<int> &q, unordered_map<int, int> &indegree_nodes,
                   unordered_map<int, list<int>> &adj_list,
                   vector<int> &result) {

  while (!q.empty()) {
    int frontNode = q.front();
    q.pop();
    result.push_back(frontNode);
    for (auto &m : adj_list[frontNode]) {
      indegree_nodes[m]--;
      if (indegree_nodes[m] == 0) {
        q.push(m);
      }
    }
  }
}
void topological_sort_bfs(int vertex, vector<pair<int, int>> &edges,
                          vector<int> &result) {

  // Create a adjacency list
  unordered_map<int, list<int>> adj_list;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second;
    adj_list[u].push_back(v);
  }

  // Create the indegree for all nodes
  unordered_map<int, int> indegree_nodes;
  for (int i = 0; i < vertex; i++) {
    indegree_nodes[i] = 0;
  }
  for (int i = 0; i < adj_list.size(); i++) {
    for (auto &m : adj_list[i]) {
      indegree_nodes[m]++;
    }
  }

  // BFS Traversal for Topological sort
  // Khan's Algorithm
  queue<int> q;
  for (int i = 0; i < vertex; i++) {
    if (indegree_nodes[i] == 0) {
      q.push(i);
    }
  }

  bfs_traversal(q, indegree_nodes, adj_list, result);
}
int main() {
  cout << "Topological Sort using BFS Traversal" << endl;
  int vertex = 6;
  vector<pair<int, int>> edges;
  vector<int> result;
  edges.push_back({0, 1});
  edges.push_back({1, 4});
  edges.push_back({1, 2});
  edges.push_back({2, 3});
  edges.push_back({3, 4});
  edges.push_back({4, 5});
  topological_sort_bfs(vertex, edges, result);

  // Print the result
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }

  return 0;
}