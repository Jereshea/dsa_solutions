/******************************************************************************

Combination of an array
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void Combination(vector<int> &arr, int start, int end, int r,
                 vector<int> partial_arr, vector<vector<int>> &output) {
  if (partial_arr.size() == r) {
    output.push_back(partial_arr);
    return;
  }

  for (int i = start; i < end; i++) {
    partial_arr.push_back(arr[i]);
    Combination(arr, i + 1, end, r, partial_arr, output);
    partial_arr.pop_back();
  }
}
int main() {
  cout << "Combination of an array" << endl;
  vector<int> arr = {1, 2, 3, 4, 5};
  vector<vector<int>> output;
  int r = 3;
  vector<int> partial_arr;
  Combination(arr, 0, arr.size(), r, partial_arr, output);

  if (output.size() > 0) {
    for (auto &p : output) {
      for (int x : p) {
        cout << x << " ";
      }
      cout << endl;
    }
  } else {
    cout << "-1" << endl;
  }

  return 0;
}