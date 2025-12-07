/******************************************************************************

Shortest Path in a graph

0 ----> 1 <------ 4 ------> 5
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

Approach:
1) Do BFS Traversal
2) Store the parent of each node if its already not visited.
3) If it is already visited, then skip storing the parents value.
4) As we are not updating the parent, it gives the shortest path between two
nodes.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void bfs_traversal(int i, queue<int> &q, unordered_map<int, bool> &visited_node,
                   unordered_map<int, int> &parent,
                   unordered_map<int, list<int>> &adj_list) {
  q.push(i);
  visited_node[i] = true;
  parent[i] = -1;

  while (!q.empty()) {
    int frontNode = q.front();
    q.pop();
    for (auto &m : adj_list[frontNode]) {
      if (!visited_node[m]) {
        visited_node[m] = true;
        q.push(m);
        parent[m] = frontNode;
      }
    }
  }
}
void bfs(int first_node, int destination_node, int vertex,
         vector<pair<int, int>> &edges, vector<int> &result) {

  // Create a adjacency list
  unordered_map<int, list<int>> adj_list;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second;
    adj_list[u].push_back(v);
  }

  // Maintain the visited Nodes
  unordered_map<int, bool> visited_node;

  // Get the parent of each nodes
  unordered_map<int, int> parent;
  queue<int> q;
  for (int i = 0; i < vertex; i++) {
    if (!visited_node[i])
      bfs_traversal(i, q, visited_node, parent, adj_list);
  }

  // Check if the destination node is present in the graph
  if (!visited_node[destination_node]) {
    cout << "Destination Node is not present in the graph" << endl;
  } else {
    cout << "Destination Node is present in the graph" << endl;
  }
  // Store the result in stack
  stack<int> s;
  int index = destination_node;
  s.push(index);
  while (index != first_node) {
    s.push(parent[index]);
    index = parent[index];
  }

  while (!s.empty()) {
    result.push_back(s.top());
    s.pop();
  }
}
int main() {
  cout << "Shortest Path in a Graph" << endl;
  int vertex = 6;
  vector<pair<int, int>> edges;
  vector<int> result;
  edges.push_back({0, 1});
  edges.push_back({1, 4});
  edges.push_back({1, 2});
  edges.push_back({2, 3});
  edges.push_back({3, 4});
  edges.push_back({4, 5});
  int first_node = 0;
  int destination_node = 5;
  bfs(first_node, destination_node, vertex, edges, result);

  // Print the result
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }

  return 0;
}
