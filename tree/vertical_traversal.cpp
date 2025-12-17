/******************************************************************************

Vertical Traversal


Example: 1
           17
       8       1
    2    6
  1
    16

Input: 17 8 2 1 -1 16 -1 -1 -1 6 -1 -1 1 -1 -1
Output: 1 2 16 8 17 6 1

Example: 2

       9
   9       1
2    6


Input: 9 9 2 -1 -1 6 -1 -1 1 -1 -1
Output: 2 9 9 6 1

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

void vertical_traversal(Tree *root, vector<int> &result) {
  if (root == NULL) {
    return;
  }

  // Maintain Horizontal Distance and Level Order
  queue<pair<Tree *, pair<int, int>>> q;
  pair<int, int> hd_level_order = make_pair(0, 0);
  pair<Tree *, pair<int, int>> horizontal_distance =
      make_pair(root, hd_level_order); // root_node, hd, level_order
  q.push(horizontal_distance);

  map<int, map<int, vector<int>>> mapping_hd_levelorder;
  mapping_hd_levelorder[horizontal_distance.second.first]
                       [horizontal_distance.second.second]
                           .push_back(horizontal_distance.first->data);

  while (!q.empty()) {
    pair<Tree *, pair<int, int>> frontNode = q.front();
    int root_node_distance = frontNode.second.first;
    q.pop();
    if (frontNode.first->left) {
      hd_level_order =
          make_pair(root_node_distance - 1, frontNode.second.second + 1);
      horizontal_distance = make_pair(frontNode.first->left, hd_level_order);
      q.push(horizontal_distance);
      mapping_hd_levelorder[horizontal_distance.second.first]
                           [horizontal_distance.second.second]
                               .push_back(horizontal_distance.first->data);
    }

    if (frontNode.first->right) {
      hd_level_order =
          make_pair(root_node_distance + 1, frontNode.second.second + 1);
      horizontal_distance = make_pair(frontNode.first->right, hd_level_order);
      q.push(horizontal_distance);
      mapping_hd_levelorder[horizontal_distance.second.first]
                           [horizontal_distance.second.second]
                               .push_back(horizontal_distance.first->data);
    }
  }

  for (auto &m : mapping_hd_levelorder) {
    for (auto &k : m.second) {
      for (auto &s : k.second) {
        // cout<<s<<" ";
        result.push_back(s);
      }
    }
  }
}

int main() {
  cout << "Binary Tree" << endl;
  Tree *root = binary_tree();
  cout << endl << endl << "Vertical Traversal of the Binary Tree" << endl;
  vector<int> result;
  vertical_traversal(root, result);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}