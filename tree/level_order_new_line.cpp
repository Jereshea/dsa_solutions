/******************************************************************************

Binary Tree (Level Order Traversal)

       4
   3       1
2    6


4 3 2 -1 -1 6 -1 -1 1 -1 -1
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

void level_order_traversal(Tree *root, vector<int> &result) {
  if (root == NULL) {
    return;
  }

  queue<Tree *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty()) {
    Tree *frontNode = q.front();

    if (frontNode == NULL) {
      cout << endl;
      q.pop();
      result.push_back(-1);

      if (!q.empty()) {
        q.push(NULL);
      }
    } else {
      result.push_back(frontNode->data);
      cout << frontNode->data << " ";
      q.pop();

      if (frontNode->left != NULL) {
        q.push(frontNode->left);
      }
      if (frontNode->right != NULL) {
        q.push(frontNode->right);
      }
    }
  }
}
int main() {
  cout << "Binary Tree" << endl;
  Tree *root = binary_tree();
  cout << endl << endl << "Level order Traversal of the Binary Tree" << endl;
  vector<int> result;
  level_order_traversal(root, result);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }

  return 0;
}