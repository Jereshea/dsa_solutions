/******************************************************************************

Permutation of a string
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void permutation(string &str, int start, int end, vector<string> &output) {
  if (start == str.size()) {
    output.push_back(str);
    return;
  }

  for (int i = start; i < end; i++) {
    swap(str[start], str[i]);
    permutation(str, start + 1, end, output);
    swap(str[i], str[start]);
  }
}
int main() {
  cout << "Permutation of an string" << endl;
  string str = "abcd";
  vector<string> output;
  permutation(str, 0, str.length(), output);

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