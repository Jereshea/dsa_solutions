/******************************************************************************

Binary Tree Maximum Path Sum:

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes
in the sequence has an edge connecting them. A node can only appear in the
sequence at most once. Note that the path does not need to pass through the
root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty
path.

        -10
    9       20
        15      7
Example 1:
1 2 -1 -1 3 -1 -1

        1
    2       3

Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Example 2:
-10 9 -1 -1 20 15 -1 -1 7 -1 -1

        -10
    9       20
          15    7

Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7
= 42.

Example 3:
-10 9 -1 -1 20 15 -1 -1 7 -1 1 -1 -1

        -10
    9       20
          15    7
                    1

Input: root = [-10,9,20,null,null,15,7, null, null, null, 1]
Output: 43
Explanation: The optimal path is 15 -> 20 -> 7 -> 1 with a path sum of 15 + 20 +
7 + 1 = 43.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Tree {
public:
  int data;
  Tree *left;
  Tree *right;

  Tree(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

Tree *binary_tree() {
  int data;
  cout << "Enter the node: " << endl;
  cin >> data;

  if (data == -1) {
    return NULL;
  }

  Tree *root = new Tree(data);
  cout << "Enter the left child of " << data << " : " << endl;
  root->left = binary_tree();
  cout << "Enter the right child of " << data << " : " << endl;
  root->right = binary_tree();

  return root;
}

void preorder_traversal(Tree *root) {
  if (root == NULL) {
    return;
  }

  cout << root->data << " ";
  preorder_traversal(root->left);
  preorder_traversal(root->right);
}

pair<int, int> maximum_path_sum(Tree *root) {
  if (root == NULL) {
    pair<int, int> p = make_pair(0, INT_MIN); // curr_path_sum, max_sum
    return p;
  }

  if (root->left == NULL && root->right == NULL) {
    pair<int, int> p =
        make_pair(root->data, root->data); // curr_path_sum, max_sum
    return p;
  }

  pair<int, int> left_tree = maximum_path_sum(root->left);
  pair<int, int> right_tree = maximum_path_sum(root->right);

  int sum_b = max(root->data, left_tree.first + root->data);
  int sum_c = max(root->data, right_tree.first + root->data);
  int sum = max(sum_b, sum_c);

  pair<int, int> p;
  p = make_pair(
      sum,
      max(root->data,
          max(right_tree.second,
              max(left_tree.second,
                  max(sum, left_tree.first + right_tree.first + root->data)))));

  return p;

  return p;
}
int main() {
  cout << "Binary Tree Maximum Path Sum" << endl;
  Tree *root = binary_tree();
  preorder_traversal(root);
  cout << endl << endl << maximum_path_sum(root).second;

  return 0;
}