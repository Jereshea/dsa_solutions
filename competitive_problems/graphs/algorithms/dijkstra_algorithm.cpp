/****************
Dijkstra's Algorithm

             (6)
        1 ---------- 4
  (4) / |            |
     /  |            |
src /   |            |
  0     | (3)        | (10)
    \   |            |
     \  |            |
 (8) \  |            |
      \ |
       2 ----------- 3
            (2)
*****************/

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<vector<int>>> &adj, int src) {

  // Create a distance vector
  vector<int> distance(adj.size(), INT_MAX);
  distance[src] = 0;

  pair<int, int> p = make_pair(0, src);
  set<pair<int, int>> dijkstra_queue;
  dijkstra_queue.insert(p);
  while (!dijkstra_queue.empty()) {
    int front_node_dist = dijkstra_queue.begin()->first;
    int front_node = dijkstra_queue.begin()->second;
    dijkstra_queue.erase(dijkstra_queue.begin());

    for (int i = 0; i < adj[front_node].size(); i++) {
      int adj_node = adj[front_node][i][0];
      int node_weight = adj[front_node][i][1];
      if (distance[front_node] + node_weight < distance[adj_node]) {
        distance[adj_node] = distance[front_node] + node_weight;
        pair<int, int> p =
            make_pair(distance[front_node] + node_weight, adj_node);
        dijkstra_queue.insert(p);
      }
    }
  }

  // Display entire result
  for (auto &m : distance) {
    cout << m << " ";
  }
  return {0, 0};
}
int main() {
  // your code goes here
  int src = 0;
  vector<vector<vector<int>>> adj = {{{1, 4}, {2, 8}},
                                     {{0, 4}, {4, 6}, {2, 3}},
                                     {{0, 8}, {3, 2}, {1, 3}},
                                     {{2, 2}, {4, 10}},
                                     {{1, 6}, {3, 10}}};
  dijkstra(adj, src);

  return 0;
}
