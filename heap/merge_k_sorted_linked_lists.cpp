/******************************************************************************

Merge K sorted linked lists
Given k sorted linked lists of different sizes, we need to merge them into a
single list while maintaining their sorted order.

Example:

1-> 3-> 5-> 7
2-> 4-> 6-> 8
0-> 9-> 10-> 11

Algorithm:
1) As it is a sorted k_linked_list, push the first element of all the k lists in
a min_heap 2) Pop the top() element to the result (say here head and tail is
maintained) 3) For every pop(), push() the next element of the popped row 4)
Repeat (2) and (3) till the size of the min_heap is greater or equal to 1 5)
Return the result

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class linked_list {
public:
  int data;
  linked_list *right;

  linked_list(int data) {
    this->data = data;
    this->right = NULL;
  }
};

class custom_op_greater {
public:
  bool operator()(linked_list *a, linked_list *b) { return a->data > b->data; }
};

linked_list *merge_k_sorted_linked_list(vector<linked_list *> &input) {
  int row = input.size();
  priority_queue<linked_list *, vector<linked_list *>, custom_op_greater> pq;
  for (int i = 0; i < row; i++) {
    pq.push(input[i]);
  }

  linked_list *head = NULL;
  linked_list *tail = NULL;
  while (pq.size() >= 1) {
    linked_list *temp = pq.top();
    pq.pop();

    if (head == NULL && tail == NULL) {
      head = new linked_list(temp->data);
      tail = head;
    } else {
      tail->right = new linked_list(temp->data);
      tail = tail->right;
    }
    if (temp->right != NULL) {
      pq.push(temp->right);
    }
  }
  return head;
}

int main() {
  cout << "Merge K sorted linked lists: ";
  vector<linked_list *> input;
  linked_list *a = new linked_list(1);
  a->right = new linked_list(3);
  a->right->right = new linked_list(5);
  a->right->right->right = new linked_list(7);
  input.push_back(a);
  linked_list *b = new linked_list(2);
  b->right = new linked_list(4);
  b->right->right = new linked_list(6);
  b->right->right->right = new linked_list(8);
  input.push_back(b);
  linked_list *c = new linked_list(0);
  c->right = new linked_list(9);
  c->right->right = new linked_list(10);
  c->right->right->right = new linked_list(11);
  input.push_back(c);
  // cout<<"Value of k: "<<input.size()<<endl;
  linked_list *result = merge_k_sorted_linked_list(input);
  while (result != NULL) {
    cout << result->data << " ";
    result = result->right;
  }

  return 0;
}