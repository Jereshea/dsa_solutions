/******************************************************************************

Addition: Singly Linked List

Input:
l1 = 2-> 4-> 3
l2 = 5-> 6-> 4
Output:
7 -> 0 -> 8
Explanation: 342 + 465 = 807
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

Node *list_addition(Node *head1, Node *head2) {
  int accumulator = 0;
  int quotient;
  Node *result_list = new Node(0);
  Node *result_copy = result_list;
  int result;
  while (head1 != NULL && head2 != NULL) {
    int data1 = head1->data;
    int data2 = head2->data;

    result = data1 + data2 + accumulator;

    if (result > 9) {
      quotient = result / 10;
      result = result % 10; // remainder
      accumulator = quotient;
    } else {
      accumulator = 0;
    }

    Node *new_node = new Node(result);
    result_copy->next_address = new_node;
    result_copy = result_copy->next_address;
    head1 = head1->next_address;
    head2 = head2->next_address;
  }

  while (head1 != NULL) {
    result = head1->data + accumulator;

    if (result > 9) {
      quotient = result / 10;
      result = result % 10; // remainder
      accumulator = quotient;
    } else {
      accumulator = 0;
    }

    Node *new_node = new Node(result);
    result_copy->next_address = new_node;
    result_copy = result_copy->next_address;
    head1 = head1->next_address;
  }

  while (head2 != NULL) {
    result = head2->data + accumulator;

    if (result > 9) {
      quotient = result / 10;
      result = result % 10; // remainder
      accumulator = quotient;
    } else {
      accumulator = 0;
    }

    Node *new_node = new Node(result);
    result_copy->next_address = new_node;
    result_copy = result_copy->next_address;
    head2 = head2->next_address;
  }

  if (accumulator > 0) {
    Node *new_node = new Node(accumulator);
    result_copy->next_address = new_node;
  }
  return result_list->next_address;
}
int main() {
  cout << "Singly Linked List" << endl;
  Node *head1 = NULL;
  insert_node_at_head(head1, 3);
  insert_node_at_head(head1, 4);
  insert_node_at_head(head1, 2);
  print_nodes(head1);

  cout << endl;
  Node *head2 = NULL;
  insert_node_at_head(head2, 9);
  insert_node_at_head(head2, 6);
  insert_node_at_head(head2, 6);
  insert_node_at_head(head2, 5);
  print_nodes(head2);

  Node *result = list_addition(head1, head2);
  cout << endl << endl << "Result:" << endl;
  while (result != NULL) {
    cout << result->data << " ";
    result = result->next_address;
  }

  return 0;
}