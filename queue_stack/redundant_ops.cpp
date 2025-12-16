/******************************************************************************

Redundant Operations

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

bool redundant_operation(string &str) {
  int count_open_bracket = 0;
  int count_close_bracket = 0;
  stack<char> s;
  for (int i = 0; i < str.size(); i++) {
    char ch = str[i];
    cout << ch << " ";

    if (ch == '(') {
      count_open_bracket++;
      s.push(ch);
    } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
      s.push(ch);
    } else if (ch == ')') {
      count_close_bracket++;
      bool is_operator = false;
      int count_ops = 0;
      while (!s.empty() && s.top() != '(') {
        is_operator = true;
        s.pop();
        count_ops++;
      }

      if (count_ops < 1) {
        return true;
      }
      if (!is_operator) {
        return true;
      }
      if (!s.empty() && s.top() == '(' && is_operator) {
        s.pop();
      }
    }
  }

  if (s.empty() && (count_open_bracket == count_close_bracket)) {
    return false;
  } else {
    return true;
  }
}
int main() {
  cout << "Redundant Operations" << endl;
  string str = "(a+b)";

  if (redundant_operation(str)) {
    cout << endl << endl;
    cout << "Series is redundant" << endl;
  } else {
    cout << endl << endl;
    cout << "Series is not redundant" << endl;
  }

  return 0;
}