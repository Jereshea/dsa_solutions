/******************************************************************************
MST:
Prim's Algorithm

      2
 (0)------(1)
  | \      |
3 |  \1    | 4
  |   \    |
 (3)------(2)
       5


Mapping
From  To  Weight
0	  1	  2
0	  3	  3
0	  2	  1
1	  2	  4
2	  3	  5

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void mst_prims(int src, int vertex, vector<pair<int, pair<int, int>>> &edges) {
  // Create Adjacency list
  unordered_map<int, vector<pair<int, int>>> adj;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second.first;
    int w = edges[i].second.second;
    pair<int, int> p1 = make_pair(v, w);
    adj[u].push_back(p1);
    pair<int, int> p2 = make_pair(u, w);
    adj[v].push_back(p2);
  }

  // Algorithm
  // STEP1: Create a key vector with INT_MAX
  vector<int> key(vertex, INT_MAX);
  key[src] = 0;

  // STEP2: Create a MST vector with false
  vector<bool> mst(vertex, false);

  // STEP3: Create a parent vector with -1
  vector<int> parent(vertex, -1);

  // Step 4: Get the minimum key (whose MST should also be False) and traverse
  // its adj

  for (int i = 0; i < vertex; i++) {
    // Get the minimum key whose MST should also be false
    int mini = INT_MAX;
    int min_index = -1;
    for (int i = 0; i < key.size(); i++) {
      if (key[i] != INT_MAX && mst[i] == false && key[i] < mini) {
        mini = key[i];
        min_index = i;
      }
    }

    // Mark the node's MST to true
    mst[min_index] = true;

    // Traverse the adj
    for (auto &m : adj[min_index]) {
      int val = m.first;
      int weight = m.second;

      if (weight < key[val]) {
        key[val] = weight;
        parent[val] = min_index;
      }
    }
  }

  cout << "Result" << endl;
  for (int i = 0; i < parent.size(); i++) {
    cout << "Parent " << parent[i] << " " << "[Weight: " << key[i] << "]" << " "
         << "To " << i << endl;
  }
}
int main() {
  cout << "Prim's MST (Minimum Spanning Tree)" << endl;
  int vertex = 4;
  vector<pair<int, pair<int, int>>> edges;
  edges.push_back({0, {1, 2}});
  edges.push_back({0, {3, 3}});
  edges.push_back({0, {2, 1}});
  edges.push_back({1, {2, 4}});
  edges.push_back({2, {3, 5}});
  int src = 0;
  mst_prims(src, vertex, edges);

  return 0;
}