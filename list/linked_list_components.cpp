/******************************************************************************

Linked List Components

You are given the head of a linked list containing unique integer values and an
integer array nums that is a subset of the linked list values. Return the number
of connected components in nums where two values are connected if they appear
consecutively in the linked list.

Input: head = [0,1,2,3], nums = [0,1,3]
Output: 2
Explanation: 0 and 1 are connected, so [0, 1] and [3] are the two connected
components.

Input: head = [0,1,2,3,4], nums = [0,3,1,4]
Output: 2
Explanation: 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4]
are the two connected components.

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

bool isdata(int val, vector<int> &nums) {
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == val) {
      nums.erase(nums.begin() + i);
      return true;
    }
  }
  return false;
}
int linked_list_components(Node *head1, vector<int> &nums) {

  if (head1 == NULL) {
    return 0;
  }

  int count = 0;
  bool flag;
  while (head1 != NULL) {
    flag = false;
    while (head1 != NULL && isdata(head1->data, nums)) {
      flag = true;
      head1 = head1->next_address;
    }

    if (head1 != NULL) {
      head1 = head1->next_address;
    }
    if (flag) {
      count++;
    }
  }
  return count;
}

int main() {
  cout << "Singly Linked List" << endl;
  Node *head1 = NULL;
  insert_node_at_head(head1, 4);
  insert_node_at_head(head1, 3);
  insert_node_at_head(head1, 2);
  insert_node_at_head(head1, 1);
  insert_node_at_head(head1, 0);
  print_nodes(head1);

  vector<int> nums = {0, 3, 1, 4};

  cout << endl << endl << "Result: " << linked_list_components(head1, nums);

  return 0;
}