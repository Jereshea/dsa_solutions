/******************************************************************************
Shortest Path:
Directed Acyclic Graph (DAG) with Weights

    (0)
   /   \
 2/     \4
 /       \
(1)----3-->(2)
  \         \
  6\         \1
    \         \
    (3) <------


Mapping
 From  To  Weight
 ----  --  ------
 0     1   2
 0     2   4
 1     2   3
 1     3   6
 2     3   1

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void topological_dfs_sort(int node, int vertex,
                          unordered_map<int, vector<pair<int, int>>> &adj,
                          vector<bool> &visited_node, stack<int> &s) {

  visited_node[node] = true;

  for (auto &m : adj[node]) {
    int individual_node = m.first;
    if (!visited_node[individual_node]) {
      topological_dfs_sort(individual_node, vertex, adj, visited_node, s);
    }
  }
  s.push(node);
}
void shortest_path(int src, int vertex,
                   vector<pair<int, pair<int, int>>> &edges) {
  // Create an adjacency List
  unordered_map<int, vector<pair<int, int>>> adj;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second.first;
    int w = edges[i].second.second;
    pair<int, int> p = make_pair(v, w);
    adj[u].push_back(p);
  }

  // Create visited Nodes
  vector<bool> visited_node(vertex);
  for (int i = 0; i < vertex; i++) {
    visited_node[i] = false;
  }

  // Find the topological sort
  vector<int> topological_sort_result;
  stack<int> s;
  for (int i = 0; i < vertex; i++) {
    if (!visited_node[i]) {
      topological_dfs_sort(i, vertex, adj, visited_node, s);
    }
  }

  // // Store the result in the topological_sort_result to check the result
  // while(!s.empty()){
  //     cout<<s.top()<<" ";
  //     topological_sort_result.push_back(s.top());
  //     s.pop();
  // }

  // Finding the shortest path from the source
  // STEP1: Initialize dist with infinity
  vector<int> distance(vertex, INT_MAX);

  // STEP2: Initialize the src with 0
  distance[src] = 0;

  // STEP3: Process the topo stack to find the min distance of each node from
  // the src
  while (!s.empty()) {

    int val = s.top();
    s.pop();
    if (distance[val] != INT_MAX) {
      // Traverse the adj list, calculate its distance from src, and update if
      // the new distance is lesser
      for (auto &x : adj[val]) {
        int index = x.first;
        int weight = x.second;

        if (distance[val] + weight < distance[index]) {
          distance[index] = distance[val] + weight;
        }
      }
    }
  }

  for (int i = 0; i < distance.size(); i++) {
    cout << distance[i] << " ";
  }
}
int main() {
  cout << "Shortest Path (DAG Graphs)" << endl;
  int vertex = 4;
  vector<pair<int, pair<int, int>>> edges;
  edges.push_back({0, {1, 2}});
  edges.push_back({0, {2, 4}});
  edges.push_back({1, {2, 3}});
  edges.push_back({1, {3, 6}});
  edges.push_back({2, {3, 1}});
  int src = 0;
  shortest_path(src, vertex, edges);

  return 0;
}