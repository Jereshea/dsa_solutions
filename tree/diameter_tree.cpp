/******************************************************************************

Diameter of the Binary Tree

       4
   3       1
2    6


4 3 2 -1 -1 6 -1 -1 1 -1 -1

Note:
Diameter of the tree never always passes from the root node
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

int height_tree(Tree *root) {
  if (root == NULL) {
    // return 0;
    // for edges
    return -1;
  }

  int left_height = height_tree(root->left);
  int right_height = height_tree(root->right);

  return (max(left_height, right_height) + 1);
}

int diameter_tree(Tree *root) {
  if (root == NULL) {
    return 0;
  }

  int left_height = height_tree(root->left);
  int right_height = height_tree(root->right);

  int left_diameter = diameter_tree(root->left);
  int right_diameter = diameter_tree(root->right);

  // return (max(left_diameter,
  // max(right_diameter,left_height+right_height+1))); for edges
  return (
      max(left_diameter, max(right_diameter, left_height + right_height + 2)));
}
int main() {
  cout << "Binary Tree" << endl;
  Tree *root = binary_tree();
  cout << endl << endl << "Diameter of the Binary Tree" << endl;
  cout << diameter_tree(root);

  return 0;
}