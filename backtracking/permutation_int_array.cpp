/******************************************************************************

Permutation of an int array
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void permutation(vector<int> &arr, int start, int end,
                 vector<vector<int>> &output) {
  if (start == arr.size()) {
    output.push_back(arr);
    return;
  }

  for (int i = start; i < end; i++) {
    swap(arr[start], arr[i]);
    permutation(arr, start + 1, end, output);
    swap(arr[i], arr[start]);
  }
}
int main() {
  cout << "Permutation of an int array" << endl;
  vector<int> arr = {3, 2, 1, 5};
  vector<vector<int>> output;
  permutation(arr, 0, arr.size(), output);

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