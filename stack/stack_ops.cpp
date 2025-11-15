/******************************************************************************

Stack

Operations:
1) push
2) peek
3) pop
4) isempty

Notes:
1) Maintain a array for each object of the stack.
2) Use size to create a stack
3) Use top to monitor the index of the latest pushed element
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
  int *arr;
  int size;
  int top;

  Stack(int size) {
    this->size = size;
    arr = new int[size];
    top = -1;
  }

  void push(int data) {
    if (top >= size - 1) {
      cout << "Stack Overflow";
    } else {
      top++;
      arr[top] = data;
    }
  }

  void pop() {
    if (top < 0) {
      cout << "Stack Underflow";
    } else {
      top--;
    }
  }

  int peek() {
    if (top < 0) {
      // cout<<"No element present in the stack";
      return -1;
    } else {
      return arr[top];
    }
  }

  bool isempty() {
    if (top < 0) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  Stack s(2);
  s.push(2);
  s.push(1);
  s.pop();
  s.push(3);

  while (!s.isempty()) {
    cout << s.peek() << " ";
    s.pop();
  }

  return 0;
}