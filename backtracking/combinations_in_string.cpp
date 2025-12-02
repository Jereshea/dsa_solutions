/******************************************************************************

Combination of a string
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void Combination(string &str, int start, int end, int r, string partial_string,
                 vector<string> &output) {
  if (partial_string.size() == r) {
    output.push_back(partial_string);
    return;
  }

  for (int i = start; i < end; i++) {
    partial_string.push_back(str[i]);
    Combination(str, i + 1, end, r, partial_string, output);
    partial_string.pop_back();
  }
}
int main() {
  cout << "Combination of an string" << endl;
  string str = "abcd";
  vector<string> output;
  int r = 2;
  string partial_string;
  Combination(str, 0, str.length(), r, partial_string, output);

  if (output.size() > 0) {
    for (auto &p : output) {
      cout << p << " ";
      cout << endl;
    }
  } else {
    cout << "-1" << endl;
  }

  return 0;
}