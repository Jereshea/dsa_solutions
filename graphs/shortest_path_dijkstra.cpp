/******************************************************************************
Shortest Path:
Dijkstra's with Weights

      2
 (0) -----> (1)
  |  \      |
  |5  \1    | 3
 \/   \/   \/
 (3)<------(2)
        1


Mapping
From To	 Weight
0	 1	 2
0 	 3	 5
0	 2	 1
1	 2	 3
2	 3	 1

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void shortest_path(int src, int vertex,
                   vector<pair<int, pair<int, int>>> &edges) {
  // Create Adjacency list
  unordered_map<int, vector<pair<int, int>>> adj;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second.first;
    int w = edges[i].second.second;
    pair<int, int> p = make_pair(v, w);
    adj[u].push_back(p);
  }

  // Algorithm
  // STEP1: Create a distance vector
  vector<int> distance(vertex);

  // STEP2: Initialize the distance of all nodes with INT_MAX
  for (int i = 0; i < vertex; i++) {
    distance[i] = INT_MAX;
  }

  // Create a priority queue OR set to store the values, as we pop the minimum
  // distance node each time
  set<pair<int, int>> weight_node;
  // STEP3: Initialize src with distance 0, every time we update the distance,
  // push it to the set
  distance[src] = 0;
  pair<int, int> ind_weight_node = make_pair(distance[src], src);
  weight_node.insert(ind_weight_node);

  // STEP4: pop() the min distance element (which is automatically did, as we do
  // set), find its adj list, calculate the dist and push it to the set
  while (!weight_node.empty()) {
    int frontNode = weight_node.begin()->second;
    weight_node.erase(weight_node.begin());

    for (auto &m : adj[frontNode]) {
      int index = m.first;
      int weight = m.second;
      if (distance[frontNode] + weight < distance[index]) {
        distance[index] = distance[frontNode] + weight;
        ind_weight_node = make_pair(distance[index], index);
        weight_node.insert(ind_weight_node);
      }
    }
  }

  // Print the Shortest Distance from source to each vertex
  for (int i = 0; i < vertex; i++) {
    cout << distance[i] << " ";
  }
}
int main() {
  cout << "Shortest Path (Dijkstra's Algorithm)" << endl;
  int vertex = 4;
  vector<pair<int, pair<int, int>>> edges;
  edges.push_back({0, {1, 2}});
  edges.push_back({0, {3, 5}});
  edges.push_back({0, {2, 1}});
  edges.push_back({1, {2, 3}});
  edges.push_back({2, {3, 1}});
  int src = 0;
  shortest_path(src, vertex, edges);

  return 0;
}