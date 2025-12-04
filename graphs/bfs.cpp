/******************************************************************************

Graph Travsersal (BFS)

You are given an undirected and disconnected graph G(V.E) having V vertices from
0 to V-1 and E edges. Your task is to print its BFS traversal starting from the
0th vertex.

here nodes = 5; edges = 6
0 ----- 1 ------- 2
|\                |
| \              |
4----------------3

Mappings

u    v
0    1, 4, 3
1    0,2
2    1, 3
3    2, 0, 4
4    0, 3


Notes:
1) Given the nodes will be from 0 to V-1 and its an disconnected graph. So when
traversing we have to make make sure that all the nodes are printed. 2) We have
to create a adjacency_list, visited_node from the given info. 3) Create a queue
and push node's neighbors in the queue, so the the traversal will be in the
order. 4) when creating adjacency_list using map, if we wanted the the list in
each adjacency_list[i] to be in sorted_oredr, we need to use 'set<int>' instead
of 'list<int>'
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void bfs(int node, int &vertex, unordered_map<int, list<int>> &adjacency_list,
         unordered_map<int, bool> &visited_node, vector<int> &ans) {

  // Store the elements in a queue to traverse in order
  queue<int> q;
  int frontNode;
  q.push(node);
  visited_node[node] = 1;

  while (!q.empty()) {
    // Push the neighbors of the node to the queue
    frontNode = q.front();
    q.pop();
    ans.push_back(frontNode);

    for (auto k : adjacency_list[frontNode]) {
      if (!visited_node[k]) {
        q.push(k);
        visited_node[k] = 1;
      }
    }
  }
}

vector<int> breadth_first_search(int vertex, vector<pair<int, int>> edges) {
  unordered_map<int, list<int>> adjacency_list;
  unordered_map<int, bool> visited_node;
  vector<int> ans;

  for (int i = 0; i < edges.size(); i++) {
    adjacency_list[edges[i].first].push_back(edges[i].second);
    adjacency_list[edges[i].second].push_back(edges[i].first);
  }

  // Initialize visited_node
  for (int i = 0; i < vertex; i++) {
    visited_node[i] = false;
  }

  // BFS
  // As the graph is a disconnected graph, we should make sure that we traverse
  // all the elements from 0 to V-1
  for (int i = 0; i < vertex; i++) {
    if (!visited_node[i]) {
      bfs(i, vertex, adjacency_list, visited_node, ans);
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
  vector<int> result = breadth_first_search(vertex, edges);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}