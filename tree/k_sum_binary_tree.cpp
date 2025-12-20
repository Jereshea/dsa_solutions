/******************************************************************************

K sum in Binary Tree

Example: 1
        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4

k = 7

Input: 3 5 6 -1 -1 2 7 -1 -1 4 -1 -1 1 0 -1 -1 8 -1 -1

Approach:

1) Store all the elements in an array.
2) Using for loop, find if the sum of nodes are equal to k.
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

void k_sum_binary_tree(Tree *root, vector<int> &arr, int k_sum, int &result) {
  if (root == NULL) {
    return;
  }
  arr.push_back(root->data);
  int sum = 0;
  for (int i = arr.size() - 1; i >= 0; i--) {
    sum += arr[i];
    if (sum == k_sum) {
      result++;
    }
  }
  k_sum_binary_tree(root->left, arr, k_sum, result);
  k_sum_binary_tree(root->right, arr, k_sum, result);

  arr.pop_back();
}
int main() {
  cout << "Binary Tree Maximum Path Sum" << endl;
  Tree *root = binary_tree();
  cout << "PreOrder Traversal" << endl;
  preorder_traversal(root);
  vector<int> arr;
  int result = 0;
  k_sum_binary_tree(root, arr, 7, result);

  // cout<<endl<<endl;
  // for(int i=0;i<arr.size();i++){
  //     cout<<arr[i]<<" ";
  // }

  cout << endl << endl << result;
  return 0;
}