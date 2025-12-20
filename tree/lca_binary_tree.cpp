/******************************************************************************

LCA in Binary Tree

Example: 1
        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4

For p = 5 and q = 1
LCA = 3

Input: 3 5 6 -1 -1 2 7 -1 -1 4 -1 -1 1 0 -1 -1 8 -1 -1
Example: 2

      3
     /
    5
   /
  6

LCA of 6 and 10
Here 10 doesn't exist, so LCA is 6

Input: 3 5 6 -1 -1 -1 -1

Approach:

1) Recurse the left tree and rigth tree seperately
2) If root->data==n1 or n2, return the root
3) Finally, if both n1 and n2 are found, return the root.
   If only one number is found, return that data alone
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

Tree *lca_binary_tree(Tree *root, int n1, int n2) {
  if (root == NULL) {
    return NULL;
  }
  if (root->data == n1 || root->data == n2) {
    return root;
  }

  Tree *left_tree = lca_binary_tree(root->left, n1, n2);
  Tree *right_tree = lca_binary_tree(root->right, n1, n2);

  if (left_tree != NULL && right_tree != NULL) {
    return root;
  } else if (left_tree != NULL && right_tree == NULL) {
    return left_tree;
  } else if (left_tree == NULL && right_tree != NULL) {
    return right_tree;
  } else {
    return NULL;
  }
}
int main() {
  cout << "Binary Tree Maximum Path Sum" << endl;
  Tree *root = binary_tree();
  preorder_traversal(root);
  cout << endl << endl << lca_binary_tree(root, 6, 5)->data;

  return 0;
}