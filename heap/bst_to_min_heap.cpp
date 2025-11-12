/******************************************************************************

Convert BST to Min Heap

Given a binary search tree which is also a complete binary tree. The problem is
to convert the given BST into a Min Heap with the condition that all the values
in the left subtree of a node should be less than all the values in the right
subtree of the node. This condition is applied to all the nodes, in the
resultant converted Min Heap.


            4
      2          6
    1   3     5     7

I/P: 4 2 1 3 6 5 7 -1
O/P: 3 2 4 1 6 5 7

Approach:
1) Perform Inorder Traversal in the BST
2) This list elements from the smallest to the largest
3) As the left node should be lesser than the right node. First fill the left
node and then fill the right node. 4) Elements has to be filled in the order NLR
(Preorder). 5) Using Inorder output, create result tree by filling in preorder.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class tree {
public:
  int data;
  tree *left;
  tree *right;

  tree(int data) {
    this->data = data;
    this->left = this->right = NULL;
  }
};

tree *build_bst(tree *&root, int data) {
  if (root == NULL) {
    root = new tree(data);
    return root;
  }

  if (root->data > data) {
    root->left = build_bst(root->left, data);
  }
  if (root->data < data) {
    root->right = build_bst(root->right, data);
  }
  return root;
}

void bst(tree *&root) {
  int data;
  cout << "Enter the nodes value [To stop: -1]: " << endl;
  cin >> data;

  while (data != -1) {
    root = build_bst(root, data);
    cin >> data;
  }
}

void inorder(tree *&root, vector<int> &result_inorder) {
  if (root == NULL) {
    return;
  }

  inorder(root->left, result_inorder);
  result_inorder.push_back(root->data);
  inorder(root->right, result_inorder);
}

void print_result(tree *&root) {
  if (root == NULL) {
    return;
  }

  print_result(root->left);
  cout << root->data << " ";
  print_result(root->right);
}

void preorder_tree(tree *&root, vector<int> &result_inorder, int &index) {
  if (root == NULL) {
    return;
  }
  root->data = result_inorder[index++];
  preorder_tree(root->left, result_inorder, index);
  preorder_tree(root->right, result_inorder, index);
}
void convert_bst_min_heap(tree *&root) {
  vector<int> result_inorder;
  inorder(root, result_inorder);
  int index = 0;
  preorder_tree(root, result_inorder, index);
}
int main() {
  cout << "Convert BST to Min Heap" << endl;
  // Create Binary Search tree
  tree *root = NULL;
  bst(root);
  convert_bst_min_heap(root);
  cout << endl << "Result:" << endl;
  print_result(root);

  return 0;
}