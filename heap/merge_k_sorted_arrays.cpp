/******************************************************************************

Merge K sorted arrays

Given a 2D matrix, mat[][] consisting of sorted arrays, where each row is sorted
in non-decreasing order, find a single sorted array that contains all the
elements from the matrix.

Example:
Input: mat[][] = [[1, 3, 5, 7], [2, 4, 6, 8], [0, 9, 10, 11]]
Output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
Explanation: Merging all elements from the 3 sorted arrays and sorting them
results in: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11].

Algorithm:
1) As it is a sorted arrays, push the first element of K arrays in a min heap.
2) Then push the top to result array.
3) Push the next element of the top_elements row to the heap
4) Proceed till all the elements in the array is pushed
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class info_node {
public:
  int data;
  int i; // row
  int j; // col

  info_node(int data, int row, int col) {
    this->data = data;
    this->i = row;
    this->j = col;
  }
};

class custom_op_greater {
public:
  bool operator()(info_node *a, info_node *b) { return a->data > b->data; }
};
vector<int> merge_k_sorted_arrays(vector<vector<int>> &input) {
  int row = input.size();
  vector<int> result;
  priority_queue<info_node *, vector<info_node *>, custom_op_greater> pq;
  int column = 0;
  for (int i = 0; i < row; i++) {
    info_node *node = new info_node(input[i][0], i, column);
    pq.push(node);
  }
  // cout<<pq.size()<<endl;
  while (pq.size() >= 1) {
    info_node *temp = pq.top();
    result.push_back(pq.top()->data);
    pq.pop();
    int curr_row = temp->i;
    int curr_col = temp->j;
    if (curr_row < row && curr_col + 1 < input[curr_row].size()) {
      info_node *node =
          new info_node(input[curr_row][curr_col + 1], curr_row, curr_col + 1);
      pq.push(node);
    }
  }

  return result;
}

int main() {
  cout << "Merge K Sorted Arrays: ";
  vector<vector<int>> input = {{1, 3, 5, 7}, {2, 4, 6, 8}, {0, 9, 10, 11}};
  // merge_k_sorted_arrays(input);
  vector<int> result = merge_k_sorted_arrays(input);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }

  return 0;
}