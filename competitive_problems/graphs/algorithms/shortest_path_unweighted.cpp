/****************
Shortest Path Unweighted Graph
*****************/

#include <bits/stdc++.h>
using namespace std;

void bfs_traversal(vector<vector<int>> &adj_list, int node,
                   vector<int> &visited_map, vector<int> &parent) {
  queue<int> q;
  q.push(node);
  visited_map[node] = 1;

  while (!q.empty()) {
    int front_node = q.front();
    q.pop();

    for (int i = 0; i < adj_list[front_node].size(); i++) {
      if (visited_map[adj_list[front_node][i]] == 0) {
        visited_map[adj_list[front_node][i]] = 1;
        q.push(adj_list[front_node][i]);
        parent[adj_list[front_node][i]] = front_node;
      }
    }
  }
}
vector<int> shortest_path(int V, int E, int S, int D,
                          vector<vector<int>> &edges) {

  vector<vector<int>> adj_list(V);
  // Create Adj_List
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];

    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }

  vector<int> visited_map(V, 0);

  vector<int> parent(V, -1);

  bfs_traversal(adj_list, S, visited_map, parent);

  // Display the result
  for (auto &m : parent) {
    cout << m << " ";
  }

  // Store the result
  if (visited_map[D] == 0) {
    return {-1};
  } else if (S == D) {
    return {S};
  } else {
    stack<int> s;
    vector<int> path;

    int index = D;
    s.push(D);
    while (parent[index] != S) {
      s.push(parent[index]);
      index = parent[index];
    }
    s.push(parent[index]);

    while (!s.empty()) {
      path.push_back(s.top());
      s.pop();
    }
    return path;
  }
}
int main() {
  // your code goes here
  int V = 8;
  int E = 10;
  int S = 0;
  int D = 7;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 3}, {3, 4}, {4, 7},
                               {3, 7}, {6, 7}, {4, 5}, {4, 6}, {5, 6}};
  vector<int> path = shortest_path(V, E, S, D, edges);
  cout << endl << endl;
  for (auto &m : path) {
    cout << m << " ";
  }

  return 0;
}
