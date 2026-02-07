/******************************************************************************
Course Schedule I

There are a total of N tasks, labeled from 0 to N-1. Given an array arr where
arr[i] = [a, b] indicates that you must take course b first if you want to take
course a. Find if it is possible to finish all tasks.

Example 1

Input: N = 4, arr = [[1,0],[2,1],[3,2]]

Output: True

Explanation: It is possible to finish all the tasks in the order : 0 1 2 3.

First, we will finish task 0. Then we will finish task 1, task 2, and task 3.

Example 2

Input: N = 4, arr = [[0,1],[3,2],[1,3],[3,0]]

Output: False

Explanation: It is impossible to finish all the tasks. Let’s analyze the pairs:

For pair {0, 1} -> we need to finish task 1 first and then task 0. (order : 1
0).

For pair{3, 2} -> we need to finish task 2 first and then task 3. (order: 2 3).

For pair {1, 3} -> we need to finish task 3 first and then task 1. (order: 3 1).

But for pair {3, 0} -> we need to finish task 0 first and then task 3 but task 0
requires task 1 and task 1 requires task 3. So, it is not possible to finish all
the tasks.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int topological_bfs(queue<int> &q, vector<int> &indegree,
                      vector<vector<int>> &adj_list) {
    int result = 0;

    while (!q.empty()) {
      int front_Node = q.front();
      q.pop();
      result = result + 1;

      for (auto m : adj_list[front_Node]) {
        indegree[m]--;
        if (indegree[m] == 0) {
          q.push(m);
        }
      }
    }
    return result;
  }
  bool canFinish(int N, vector<vector<int>> arr) {
    vector<int> topo_order;
    vector<int> indegree(N, 0);
    vector<vector<int>> adj_list(N);

    for (int i = 0; i < arr.size(); i++) {
      int u = arr[i][1];
      int v = arr[i][0];
      indegree[v]++;
      adj_list[u].push_back(v);
    }

    // Topological Order _ BFS
    queue<int> q; // 2->4 -> 1
    for (int i = 0; i < N; i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }
    int result = topological_bfs(q, indegree, adj_list);
    if (result == N) {
      return true;
    }
    return false;
  }
};

int main() {
  cout << "Course Schedule I" << endl;
  // int N = 4;
  // vector<vector<int>> arr = {{1,0},{2,1},{3,2}};
  int N = 4;
  vector<vector<int>> arr = {{0, 1}, {3, 2}, {1, 3}, {3, 0}};
  Solution sol;
  cout << sol.canFinish(N, arr);
  return 0;
}