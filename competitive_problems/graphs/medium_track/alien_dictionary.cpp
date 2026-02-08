/***********
Alien Dictionary

Given a sorted dictionary of an alien language having N words and K starting
alphabets of a standard dictionary. Find the order of characters in the alien
language.

There may be multiple valid orders for a particular test case, thus you may
return any valid order as a string. The output will be True if the order
returned by the function is correct, else False denoting an incorrect order. If
the given arrangement of words is inconsistent with any possible letter
ordering, return an empty string "".


Example 1

Input: N = 5, K = 4, dict = ["baa","abcd","abca","cab","cad"]



Output: b d a c



Explanation:

We will analyze every consecutive pair to find out the order of the characters.

The pair “baa” and “abcd” suggests ‘b’ appears before ‘a’ in the alien
dictionary.

The pair “abcd” and “abca” suggests ‘d’ appears before ‘a’ in the alien
dictionary.

The pair “abca” and “cab” suggests ‘a’ appears before ‘c’ in the alien
dictionary.

The pair “cab” and “cad” suggests ‘b’ appears before ‘d’ in the alien
dictionary.

So, [‘b’, ‘d’, ‘a’, ‘c’] is a valid ordering.

Example 2

Input: N = 3, K = 3, dict = ["caa","aaa","aab"]



Output: c a b



Explanation: Similarly, if we analyze the consecutive pair

for this example, we will figure out [‘c’, ‘a’, ‘b’] is

a valid ordering.
*************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string findOrder(string dict[], int N, int K) {
    vector<vector<int>> adj_list(K);
    vector<int> indegree(K, 0);

    for (int i = 0; i < N - 1; i++) {
      string a = dict[i];
      string b = dict[i + 1];
      int index_1 = 0;
      int index_2 = 0;
      while (index_1 < a.length() && index_2 < b.length()) {
        if (a[index_1] != b[index_2]) {
          int node_1 = a[index_1] - 'a';
          int node_2 = b[index_2] - 'a';

          adj_list[node_1].push_back(node_2);
          indegree[node_2]++;
          break;
        }
        index_1 = index_1 + 1;
        index_2 = index_2 + 1;
      }
    }

    // Perform topologice sort
    queue<int> q;
    string result = "";
    for (int i = 0; i < K; i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      int front_node = q.front();
      q.pop();
      result += (front_node + 'a');

      for (int i = 0; i < adj_list[front_node].size(); i++) {
        indegree[adj_list[front_node][i]]--;
        if (indegree[adj_list[front_node][i]] == 0) {
          q.push(adj_list[front_node][i]);
        }
      }
    }

    return result;
  }
};

int main() {
  // your code goes here
  cout << "Alien Dictionary" << endl;
  // 	int N = 5;
  // 	int K = 4;
  // 	string dict[N] = {"baa","abcd","abca","cab","cad"};
  int N = 3;
  int K = 3;
  string dict[N] = {"caa", "aaa", "aab"};
  Solution sol;
  cout << sol.findOrder(dict, N, K);
}
