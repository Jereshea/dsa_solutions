/******************************************************************************

Binary Tree (Postorder Traversal)

       4
   3       1
2    6


4 3 2 -1 -1 6 -1 -1 1 -1 -1

Output: 2 6 3 1 4
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

void postorder_traversal(Tree *root, vector<int> &result) {
  if (root == NULL) {
    return;
  }

  postorder_traversal(root->left, result);
  postorder_traversal(root->right, result);
  result.push_back(root->data);
}
int main() {
  cout << "Binary Tree" << endl;
  Tree *root = binary_tree();
  cout << endl << endl << "postorder Traversal of the Binary Tree" << endl;
  vector<int> result;
  postorder_traversal(root, result);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }

  return 0;
}