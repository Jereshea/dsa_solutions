/******************************************************************************

Subsequence of an array

Visualization of Approach:
                               []
                        /              \
                     [3]                []
                 /        \          /       \
            [3,5]        [3]       [5]         []
           /    \       /   \    /   \       /   \
     [3,5,9] [3,5] [3,9]    [3] [5,9] [5] [9]    []

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void subsequence(vector<int> &arr, int start, int end,
                 vector<int> partial_output, vector<vector<int>> &output) {
  if (start >= arr.size()) {
    output.push_back(partial_output);
    return;
  }

  partial_output.push_back(arr[start]);
  subsequence(arr, start + 1, end, partial_output, output);
  partial_output.pop_back();
  subsequence(arr, start + 1, end, partial_output, output);
}
int main() {
  cout << "Subsequence of an Array" << endl;
  vector<int> arr = {3, 2, 1};
  vector<vector<int>> output;
  vector<int> partial_output;
  subsequence(arr, 0, arr.size(), partial_output, output);

  for (auto &p : output) {
    for (int x : p) {
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}