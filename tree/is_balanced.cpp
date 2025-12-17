/******************************************************************************

Balanced Binary Tree
Example: 1
       4
   3       1
2    6


4 3 2 -1 -1 6 -1 -1 1 -1 -1

Example: 2

               4
           3       1
        2    6
    12
  5


4 3 2 12 5 -1 -1 -1 -1 6 -1 -1 1 -1 -1

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

bool is_balanced_tree(Tree *root) {
  if (root == NULL) {
    return true;
  }

  int left_height = height_tree(root->left);
  int right_height = height_tree(root->right);

  int balance = abs(left_height - right_height);

  if (balance > 1) {
    return false;
  }

  if (!is_balanced_tree(root->left)) {
    return false;
  }
  if (!is_balanced_tree(root->right)) {
    return false;
  }

  return true;
}
int main() {
  cout << "Binary Tree" << endl;
  Tree *root = binary_tree();
  cout << endl << endl << "Balanced Binary Tree" << endl;
  cout << is_balanced_tree(root);
  return 0;
}