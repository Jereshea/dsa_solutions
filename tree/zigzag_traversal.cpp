/******************************************************************************

ZigZag Traversal


Example: 1
       17
   8       1
2    6


Input: 17 8 2 -1 -1 6 -1 -1 1 -1 -1
Output: 17 1 8 2 6

Example: 2

       9
   9       1
2    6


Input: 9 9 2 -1 -1 6 -1 -1 1 -1 -1
Output: 9 1 9 2 6

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

void zigzag_traversal(Tree *root, vector<int> &result) {

  if (root == NULL) {
    return;
  }

  queue<Tree *> q;
  q.push(root);
  bool left_to_right = true;
  while (!q.empty()) {
    int size = q.size();
    vector<int> arr(size);
    if (left_to_right) {
      for (int i = 0; i < size; i++) {
        Tree *frontNode = q.front();
        arr[i] = frontNode->data;
        q.pop();

        if (frontNode->left != NULL) {
          q.push(frontNode->left);
        }
        if (frontNode->right != NULL) {
          q.push(frontNode->right);
        }
      }
    } else {
      for (int j = size - 1; j >= 0; j--) {
        Tree *frontNode = q.front();
        arr[j] = frontNode->data;
        q.pop();

        if (frontNode->left != NULL) {
          q.push(frontNode->left);
        }
        if (frontNode->right != NULL) {
          q.push(frontNode->right);
        }
      }
    }

    left_to_right = !left_to_right;

    for (int k = 0; k < arr.size(); k++) {
      result.push_back(arr[k]);
    }
  }
}
int main() {
  cout << "Binary Tree" << endl;
  Tree *root = binary_tree();
  cout << endl << endl << "ZigZag Traversal of the Binary Tree" << endl;
  vector<int> result;
  zigzag_traversal(root, result);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}