/****************
Shortest Path Unweighted Graph
*****************/

#include <bits/stdc++.h>
using namespace std;

void bfs_traversal(vector<vector<int>> &adj, vector<int> &indegree_node,
                   vector<int> &topological_sort, queue<int> &q) {

  while (!q.empty()) {
    int front_node = q.front();
    q.pop();

    for (int i = 0; i < adj[front_node].size(); i++) {
      indegree_node[adj[front_node][i]]--;
      if (indegree_node[adj[front_node][i]] == 0) {
        topological_sort.push_back(adj[front_node][i]);
        q.push(adj[front_node][i]);
      }
    }
  }
}
vector<int> shortest_path_dag_graph(vector<vector<int>> &adj) {

  vector<int> indegree_node(adj.size(), 0);

  // Collect the Indegree of each nodes
  for (int i = 0; i < adj.size(); i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      indegree_node[adj[i][j]]++;
    }
  }

  // for(auto &m:indegree_node){
  //     cout<<m<<" ";
  // }

  // bfs_traversal
  vector<int> topological_sort;
  queue<int> q;
  for (int i = 0; i < indegree_node.size(); i++) {
    if (indegree_node[i] == 0) {
      topological_sort.push_back(i);
      q.push(i);
    }
  }
  bfs_traversal(adj, indegree_node, topological_sort, q);

  return topological_sort;
}
int main() {
  // your code goes here
  vector<vector<int>> adj = {{1}, {2}, {}, {2, 4}, {}};
  vector<int> topological_sort = shortest_path_dag_graph(adj);
  for (auto &m : topological_sort) {
    cout << m << " ";
  }

  return 0;
}
