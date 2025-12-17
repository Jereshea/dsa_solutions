/******************************************************************************

Boundary Traversal


Example: 1
           17
       8       1z
    2    6
  1
    16

Input: 17 8 2 1 -1 16 -1 -1 -1 6 -1 -1 1 -1 -1
Output: 17 8 2 1 16 6 1

Example: 2

       9
   9       1
2    6


Input: 9 9 2 -1 -1 6 -1 -1 1 -1 -1
Output: 9 9 2 6 1

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

void left_node(Tree *root, vector<int> &result) {
  if (root == NULL) {
    return;
  }

  if (root->left == NULL && root->right == NULL) {
    return;
  }

  if (root->left != NULL) {
    result.push_back(root->data);
    left_node(root->left, result);
  } else {
    result.push_back(root->data);
    left_node(root->right, result);
  }
}

void child_node(Tree *root, vector<int> &result) {
  if (root == NULL) {
    return;
  }

  if (root->left == NULL && root->right == NULL) {
    result.push_back(root->data);
  }

  child_node(root->left, result);
  child_node(root->right, result);
}

void right_node(Tree *root, vector<int> &result) {
  if (root == NULL) {
    return;
  }

  if (root->left == NULL && root->right == NULL) {
    return;
  }

  if (root->right != NULL) {
    right_node(root->right, result);
    result.push_back(root->data);
  } else {
    right_node(root->left, result);
    result.push_back(root->data);
  }
}

void boundary_traversal(Tree *root, vector<int> &result) {
  if (root == NULL) {
    return;
  }

  // Left Nodes
  left_node(root, result);

  // Child Nodes
  child_node(root, result);

  // Right child (Print from bottom to top)
  right_node(
      root->right,
      result); // To not print the root data again, we pass only root->right
}

int main() {
  cout << "Binary Tree" << endl;
  Tree *root = binary_tree();
  cout << endl << endl << "Boundary Traversal of the Binary Tree" << endl;
  vector<int> result;
  boundary_traversal(root, result);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}