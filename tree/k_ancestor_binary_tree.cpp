/******************************************************************************

K Ancestor in Binary Tree

Example: 1
        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4

k = 7
k_ancestor=2
output: 5

Input: 3 5 6 -1 -1 2 7 -1 -1 4 -1 -1 1 0 -1 -1 8 -1 -1

Approach:

1) Store all the elements in an array till k is found.
2) With the updated array return the k_ancestor
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

bool k_ancestor_binary_tree(Tree *root, vector<int> &arr, int k) {
  if (root == NULL) {
    return false;
  }

  if (root->data == k) {
    return true;
  }
  arr.push_back(root->data);

  if (k_ancestor_binary_tree(root->left, arr, k)) {
    return true;
  }
  if (k_ancestor_binary_tree(root->right, arr, k)) {
    return true;
  }

  arr.pop_back();
  return false;
}

int k_binary_tree(Tree *root, vector<int> &arr, int k, int k_ancestor) {
  if (k_ancestor_binary_tree(root, arr, k) && k_ancestor < arr.size()) {
    return arr[arr.size() - k_ancestor];
  } else {
    return 0;
  }
}
int main() {
  cout << "K Ancestor in a Binary Tree" << endl;
  Tree *root = binary_tree();
  cout << "PreOrder Traversal" << endl;
  preorder_traversal(root);
  vector<int> arr;
  int k = 7;
  int k_ancestor = 2;
  cout << endl << endl << "Result: " << k_binary_tree(root, arr, k, k_ancestor);

  return 0;
}