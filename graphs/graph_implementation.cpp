/******************************************************************************

Graph (Adjacency List)

here nodes = 5; edges = 6
3 ----- 5 ------- 7
|\                |
| \              |
2---------------- 1

Mapping

u    v
3    5, 1, 2
5    7, 3
7    5, 1
1    7, 2, 3
2    3, 1


Input:
Enter the number of nodes: 5
Enter the number of edges: 6
3 5
5 7
7 1
1 2
1 3
2 3

3 5 5 7 7 1 1 2 1 3 2 3
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
class Graph {
public:
  unordered_map<int, list<int>> adjacency_list;

  void add_edge(int u, int v, bool is_directed) {
    adjacency_list[u].push_back(v);

    if (!is_directed) {
      adjacency_list[v].push_back(u);
    }
  }

  void print_graph() {
    for (auto &m : adjacency_list) {
      for (int x : m.second) {
        cout << m.first << " -> " << x << endl;
      }
      cout << endl;
    }
  }
};
int main() {
  cout << "Graph" << endl;
  int n, m, u, v;
  cout << "Enter the number of nodes: " << endl;
  cin >> n;
  cout << "Enter the number of edges: " << endl;
  cin >> m;
  Graph g;
  for (int i = 0; i < m; i++) {
    cout << "Enter the node (u) and its connected node (v)" << endl;
    cin >> u >> v;
    g.add_edge(u, v, 0);
  }
  g.print_graph();
  return 0;
}