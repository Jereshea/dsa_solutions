/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class node {
public:
  int data;
  node *next;
  node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

void node_insert(node *&head, int data) {
  if (head == NULL) {
    head = new node(data);
    return;
  }

  node *curr = head;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = new node(data);

  return;
}

node *merge(node *left, node *right) {
  if (left == NULL && right != NULL) {
    return right;
  }
  if (right == NULL && left != NULL) {
    return left;
  }

  if (left->data < right->data) {
    left->next = merge(left->next, right);
    return left;
  } else {
    right->next = merge(left, right->next);
    return right;
  }
}

node *get_mid(node *head) {
  // find mid ptr (ptr1 is the mid ptr)
  node *ptr1 = NULL;
  node *ptr2 = NULL;
  if (head != NULL) {
    ptr1 = head;
  }

  if (head->next != NULL) {
    ptr2 = head->next;
  }

  while (ptr2 != NULL && ptr2->next != NULL) {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
    if (ptr2->next != NULL) {
      ptr2 = ptr2->next;
    }
  }
  return ptr1;
}

node *mergeSort(node *head) {
  // Write your code here.

  if (head == NULL || head->next == NULL) {
    return head;
  }

  node *mid = get_mid(head);
  node *right = mid->next;
  mid->next = NULL;

  node *left = mergeSort(head);
  right = mergeSort(right);
  return merge(left, right);
}

int main() {
  cout << "Merge Sort in Linked List" << endl;
  // 1 4 5 2 -1
  node *head = NULL;
  node_insert(head, 1);
  node_insert(head, 4);
  node_insert(head, 5);
  node_insert(head, 2);

  // while(head!=NULL){
  //     cout<<head->data<<" ";
  //     head=head->next;
  // }

  head = mergeSort(head);
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }

  return 0;
}