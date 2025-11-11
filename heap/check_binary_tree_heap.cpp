/******************************************************************************

Check if a Binary Tree is a Heap?

          40
    20          30
10      5

I/p: 40 20 10 -1 -1 5 -1 -1 30 -1 -1
I/p: 40 20 10 -1 -1 5 -1 -1 30 -1 50 -1 -1
I/p: 40 20 10 -1 -1 5 -1 -1 30 50 -1 -1 -1

Code_Demonstration:
1) Created a binary tree
2) For the verification of binary tree, the tree is visualized by level_order
3) The created binary_tree is checked for heap
   Heap_Condition: i) Validate complete Binary Tree
                   ii) Heapify: Validate the root is greater than its children
(bottom-up)

Time Complexity: O(n)
Space Complexity: O(n)
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

tree *build_binary_tree(tree *root) {
  int data;
  cout << "Enter the data (To stop: -1): " << endl;
  cin >> data;

  if (data == -1) {
    return NULL;
  }

  root = new tree(data);
  cout << "Enter the left child of " << data << endl;
  root->left = build_binary_tree(root->left);
  cout << "Enter the right child of " << data << endl;
  root->right = build_binary_tree(root->right);

  return root;
}

void level_order(tree *root) {
  if (root == NULL) {
    return;
  }

  queue<tree *> q;
  q.push(root);
  while (!q.empty()) {
    tree *temp = q.front();
    q.pop();
    cout << temp->data << " ";
    if (temp->left) {
      q.push(temp->left);
    }
    if (temp->right) {
      q.push(temp->right);
    }
  }
}

int nodes_count(tree *root) {
  if (root == NULL) {
    return 0;
  }

  int left = nodes_count(root->left);
  int right = nodes_count(root->right);

  return left + right + 1;
}

bool is_complete_bt(tree *root, int index, int total_nodes) {
  // Check for every nodes, does the left and right child is lesser than
  // total_nodes
  if (root == NULL) {
    return true;
  }

  int left_child = 2 * index;
  int right_child = 2 * index + 1;
  // cout<<"Node: "<<root->data<<" Index: "<<index<<" Left_Child:
  // "<<left_child<<" Right_Child: "<<right_child<<endl;

  if (index > total_nodes) {
    return false;
  }

  bool left_tree = is_complete_bt(root->left, left_child, total_nodes);
  bool right_tree = is_complete_bt(root->right, right_child, total_nodes);

  return left_tree && right_tree;
}

bool heapify(tree *root) {
  if (root == NULL) {
    return true;
  }

  if (root->left == NULL && root->right == NULL) {
    return true;
  }

  if (root->right == NULL && root->left != NULL &&
      (root->data < root->left->data)) {
    return false;
  }

  if (root->right != NULL && root->left == NULL &&
      (root->data < root->right->data)) {
    return false;
  }

  if ((root->left != NULL && root->data < root->left->data) ||
      (root->right != NULL && root->data < root->right->data)) {
    return false;
  }
  bool left = heapify(root->left);
  bool right = heapify(root->right);

  return left && right;
}

bool is_heap(tree *root) {
  // Condition:1 -> is_complete_bt()
  // Condition:2 -> is_heap()
  int total_nodes = nodes_count(root);
  if (is_complete_bt(root, 1, total_nodes) && heapify(root)) {
    return true;
  } else {
    return false;
  }
}
int main() {
  cout << "Check if a Binary Tree is a Heap" << endl;
  tree *root = NULL;
  root = build_binary_tree(root);
  cout << endl << "Level Order of the Binary Tree" << endl;
  level_order(root);
  cout << endl
       << endl
       << "No of nodes in the Binary Tree: " << nodes_count(root) << endl;

  if (is_heap(root)) {
    cout << endl << endl << "Yes, the given Binary Tree is a Heap" << endl;
  } else {
    cout << endl << endl << "No, the given Binary Tree is not a Heap" << endl;
  }

  return 0;
}
