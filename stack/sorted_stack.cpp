/******************************************************************************

Sorted Stack: Print from the largest to the smallest element

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
class Stack {
public:
  int *arr;
  int top;
  int size;

  Stack(int size) {
    this->size = size;
    this->top = -1;
    arr = new int[size];
  }

  void insert(int data) {
    if (top >= size - 1) {
      cout << "Stack Overflow";
    } else {
      top++;
      arr[top] = data;
    }
  }

  int peek() {
    if (top == -1) {
      cout << "Stack is empty";
      return -1;
    } else {
      return arr[top];
    }
  }

  void pop() {
    if (top == -1) {
      cout << "Stack Underflow";
    } else {
      top--;
    }
  }

  bool isempty() {
    if (top == -1) {
      return true;
    } else {
      return false;
    }
  }

  ~Stack() { delete[] arr; }
};

void sort_elements(Stack &s, int curr_element) {
  if (s.isempty()) {
    s.insert(curr_element);
    return;
  }

  if (s.peek() < curr_element) {
    s.insert(curr_element);
    return;
  } else {
    int element = s.peek();
    s.pop();
    sort_elements(s, curr_element);
    s.insert(element);
  }
}
void sorted_stack(Stack &s) {
  // Step:1 Empty the stack using backtrack
  if (s.isempty()) {
    return;
  }

  int curr_element = s.peek();
  s.pop();
  sorted_stack(s);

  // Step:2 Insert the elements back to stack in sorted way
  sort_elements(s, curr_element);
}
int main() {
  cout << "Sorted Stack" << endl;
  Stack s(5);
  s.insert(50);
  s.insert(10);
  s.insert(40);
  s.insert(5);
  s.insert(12);
  // cout<<s.peek()<<endl;
  // s.pop();
  // cout<<s.isempty()<<endl;

  sorted_stack(s);
  while (!s.isempty()) {
    cout << s.peek() << " ";
    s.pop();
  }

  return 0;
}