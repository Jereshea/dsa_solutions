/******************************************************************************

Is Loop present in the Linked List

Approach:
1) Maintain hash map to store visited nodes.
2) If the node is already visited, then loop is present.

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

void circular_linked_list(Node *&head1) {
  Node *temp = head1;

  while (temp->next_address != NULL) {
    temp = temp->next_address;
  }
  temp->next_address = head1;
}
void print_nodes(Node *&head) {
  Node *temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next_address;
  }
}

bool is_loop_present(Node *head1) {
  unordered_map<int, bool> visited;

  if (head1 == NULL) {
    return false;
  }
  while (head1 != NULL) {
    if (visited[head1->data]) {
      return true;
    } else {
      visited[head1->data] = true;
      head1 = head1->next_address;
    }
  }

  return false;
}
int main() {
  cout << "Singly Linked List" << endl;
  Node *head1 = NULL;
  insert_node_at_head(head1, 3);
  insert_node_at_head(head1, 4);
  insert_node_at_head(head1, 2);
  insert_node_at_head(head1, 1);
  insert_node_at_head(head1, 0);
  circular_linked_list(head1);
  // print_nodes(head1);

  if (is_loop_present(head1)) {
    cout << "Loop is present in the Linked List" << endl;
  } else {
    cout << "Loop is not present in the Linked List" << endl;
  }

  return 0;
}