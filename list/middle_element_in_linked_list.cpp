/******************************************************************************

Middle Element in a Singly Linked List

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

Node *middle_element(Node *head1) {
  if (head1 != NULL) {
    Node *first_ptr = head1;

    if (first_ptr->next_address != NULL) {
      Node *second_ptr = head1->next_address;
      while (second_ptr->next_address != NULL) {
        first_ptr = first_ptr->next_address;
        second_ptr = second_ptr->next_address;
        if (second_ptr->next_address != NULL) {
          second_ptr = second_ptr->next_address;
        }
      }
    }
    return first_ptr;
  } else {
    return NULL;
  }
}
int main() {
  cout << "Singly Linked List" << endl;
  Node *head1 = NULL;
  insert_node_at_head(head1, 3);
  insert_node_at_head(head1, 4);
  insert_node_at_head(head1, 2);
  print_nodes(head1);

  Node *result = middle_element(head1);
  if (result) {
    cout << endl << endl << "Result:" << result->data << endl;
  } else {
    cout << endl << endl << "The List is empty" << endl;
  }

  return 0;
}