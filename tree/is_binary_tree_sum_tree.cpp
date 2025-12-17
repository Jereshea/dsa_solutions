/******************************************************************************

Check if a given Binary Tree is Sum Tree


Given a binary tree, the task is to check if it is a Sum Tree. A Sum Tree is a
Binary Tree where the value of a node is equal to the sum of the nodes present
in its left subtree and right subtree. An empty tree is Sum Tree and the sum of
an empty tree can be considered as 0. A leaf node is also considered a Sum Tree.


Example: 1
       17
   8       1
2    6


Input: 17 8 2 -1 -1 6 -1 -1 1 -1 -1
Output: 1 (true)

Example: 2

       9
   9       1
2    6


Input: 9 9 2 -1 -1 6 -1 -1 1 -1 -1
Output: 0 (False)

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
  cout << "Enter the node value: " << endl;
  cin >> data;

  if (data == -1) {
    return NULL;
  }

  Tree *root = new Tree(data);
  cout << "Enter the left child of the node " << data << " : " << endl;
  root->left = binary_tree();
  cout << "Enter the right child of the node " << data << " : " << endl;
  root->right = binary_tree();

  return root;
}

pair<int, bool> sum_tree(Tree *root) {
  if (root == NULL) {
    pair<int, bool> p = make_pair(0, true);
    return p;
  }

  if (root->left == NULL && root->right == NULL) {
    pair<int, bool> p = make_pair(root->data, true);
    return p;
  }

  pair<int, bool> left_sum_tree = sum_tree(root->left);
  if (!left_sum_tree.second) {
    pair<int, bool> p = make_pair(0, false);
    return p;
  }
  pair<int, bool> right_sum_tree = sum_tree(root->right);
  if (!right_sum_tree.second) {
    pair<int, bool> p = make_pair(0, false);
    return p;
  }
  int a = left_sum_tree.first;
  int b = right_sum_tree.first;

  int c = a + b;
  // cout<<"SUM: a "<<a<<endl;
  // cout<<"SUM: b "<<b<<endl;

  if (c != root->data) {
    pair<int, bool> p = make_pair(c + root->data, false);
    return p;
  }

  pair<int, bool> p = make_pair(c + root->data, true);
  return p;
}

bool is_sum_tree(Tree *root) {

  if (root == NULL) {
    return true;
  }
  pair<int, bool> p = sum_tree(root);
  if (p.second) {
    return true;
  } else {
    return false;
  }
}
int main() {
  cout << "Binary Tree" << endl;
  Tree *root = binary_tree();
  cout << endl << endl << "Is Binary Tree a Sum Tree" << endl;
  cout << is_sum_tree(root);
  return 0;
}