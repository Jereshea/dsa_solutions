/******************************************************************************

K Reversal in a Singly Linked List

k=3
7 6 5 4 3 2 1

5 6 7 2 3 4 1


Approach:

Assign prev=next=NULL
Update prev, curr, next regularly

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next_address;

  Node(int data) {
    this->data = data;
    this->next_address = NULL;
  }
};

void insert_node_at_head(Node *&head, int data) {
  Node *temp = head;
  if (temp == NULL) {
    Node *new_node = new Node(data);
    temp = new_node;
  } else {
    Node *new_node = new Node(data);
    new_node->next_address = temp;
    temp = new_node;
  }
  head = temp;
}

void insert_node_at_tail(Node *&head, int data) {
  Node *temp = head;
  if (temp == NULL) {
    Node *new_node = new Node(data);
    head = new_node;
  } else {
    while (temp->next_address != NULL) {
      temp = temp->next_address;
    }
    Node *new_node = new Node(data);
    temp->next_address = new_node;
  }
}

void insert_node_after_a_node(Node *&head, int data1, int data2) {
  Node *temp = head;
  while (temp != NULL && temp->data != data2) {
    temp = temp->next_address;
  }
  if (temp == NULL) {
    cout << "The element is not present" << endl;
  } else {
    Node *new_node = new Node(data1);
    if (temp->next_address == NULL) {
      temp->next_address = new_node;
    } else {
      new_node->next_address = temp->next_address;
      temp->next_address = new_node;
    }
  }
}

void insert_node_before_a_node(Node *&head, int data1, int data2) {
  Node *temp = head;
  if (temp != NULL && temp->data == data2) {
    Node *new_node = new Node(data1);
    new_node->next_address = temp;
    temp = new_node;
    head = temp;
  } else {
    while (temp->next_address != NULL && temp->next_address->data != data2) {
      temp = temp->next_address;
    }
    if (temp->next_address == NULL) {
      cout << "The element is not present" << endl;
    } else {
      Node *new_node = new Node(data1);
      new_node->next_address = temp->next_address;
      temp->next_address = new_node;
    }
  }
}

void print_nodes(Node *&head) {
  Node *temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next_address;
  }
}

Node *k_reverse(Node *&head1, int k) {
  Node *prev = NULL;
  Node *next = NULL;
  Node *curr = head1;

  while (curr != NULL && k > 0) {
    next = curr->next_address;
    curr->next_address = prev;
    prev = curr;
    curr = next;
    k--;
  }

  if (next != NULL) {
    head1->next_address = k_reverse(next, 3);
  }
  return prev;
}
int main() {
  cout << "Singly Linked List" << endl;
  Node *head1 = NULL;
  insert_node_at_head(head1, 3);
  insert_node_at_head(head1, 4);
  insert_node_at_head(head1, 2);
  insert_node_at_head(head1, 1);
  insert_node_at_head(head1, 0);
  print_nodes(head1);

  Node *result = k_reverse(head1, 3);
  cout << endl << endl;
  while (result != NULL) {
    cout << result->data << " ";
    result = result->next_address;
  }

  return 0;
}