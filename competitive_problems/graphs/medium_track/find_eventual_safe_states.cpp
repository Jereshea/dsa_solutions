/******************************************************************************
Find eventual safe states

Given a directed graph with V vertices labeled from 0 to V-1. The graph is
represented using an adjacency list where adj[i] lists all nodes adjacent to
node i, meaning there is an edge from node i to each node in adj[i]. A node is a
terminal node if there are no outgoing edges. A node is a safe node if every
possible path starting from that node leads to a terminal node. Return an array
containing all the safe nodes of the graph in ascending order.

Example 1

Input: V = 7, adj= [[1,2], [2,3], [5], [0], [5], [], []]

Output: [2, 4, 5, 6]

Explanation:

From node 0: two paths are there 0->2->5 and 0->1->3->0.

The second path does not end at a terminal node. So it is not

a safe node.

From node 1: two paths exist: 1->3->0->1 and 1->2->5.

But the first one does not end at a terminal node. So it is not a safe node.

From node 2: only one path: 2->5 and 5 is a terminal node.

So it is a safe node.

From node 3: two paths: 3->0->1->3 and 3->0->2->5

but the first path does not end at a terminal node.

So it is not a safe node.

From node 4: Only one path: 4->5 and 5 is a terminal node.

So it is also a safe node.

From node 5: It is a terminal node.

So it is a safe node as well.

From node 6: It is a terminal node.

So it is a safe node as well.

Example 2

Input: V = 4, adj= [[1], [2], [0,3], []]

Output: [3]

Explanation: Node 3 itself is a terminal node and it is a safe node as well. But
all the paths from other nodes do not lead to a terminal node.So they are
excluded from the answer.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void topological_bfs(queue<int> &q, vector<int> &indegree,
                       vector<vector<int>> &adj_list_reversed,
                       vector<int> &result) {

    while (!q.empty()) {
      int front_Node = q.front();
      q.pop();
      result.push_back(front_Node);

      for (auto m : adj_list_reversed[front_Node]) {
        indegree[m]--;
        if (indegree[m] == 0) {
          q.push(m);
        }
      }
    }
  }
  vector<int> eventualSafeNodes(int V, vector<vector<int>> &adj) {

    vector<int> indegree(V, 0);
    vector<int> result;
    vector<vector<int>> adj_list_reversed(V);

    /*
    Approach
        1. Reverse the graph
        2. Find the topological sort
    */
    for (int u = 0; u < adj.size(); u++) {
      for (int v = 0; v < adj[u].size(); v++) {
        adj_list_reversed[adj[u][v]].push_back(u);
        indegree[u]++;
      }
    }

    // Topological Order _ BFS
    queue<int> q;
    for (int i = 0; i < V; i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }
    topological_bfs(q, indegree, adj_list_reversed, result);

    sort(result.begin(), result.end());
    return result;
  }
};

int main() {
  cout << "Find eventual safe states" << endl;
  int V = 7;
  vector<vector<int>> adj = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
  Solution sol;
  vector<int> result = sol.eventualSafeNodes(V, adj);
  for (auto x : result) {
    cout << x << " ";
  }
  return 0;
}