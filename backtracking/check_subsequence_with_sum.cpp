/******************************************************************************

Check what are the subsequences of sum=sum_check

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

void subsequence(vector<int> &arr, int start, int end, int sum,
                 vector<int> partial_output, vector<vector<int>> &output) {
  if (start >= arr.size()) {
    int sum_array = 0;
    for (int i = 0; i < partial_output.size(); i++) {
      sum_array += partial_output[i];
    }
    if (sum_array == sum) {
      output.push_back(partial_output);
    }
    return;
  }

  partial_output.push_back(arr[start]);
  subsequence(arr, start + 1, end, sum, partial_output, output);
  partial_output.pop_back();
  subsequence(arr, start + 1, end, sum, partial_output, output);
}
int main() {
  cout << "Check what are the subsequences of sum==sum_check" << endl;
  vector<int> arr = {3, 2, 1, 5};
  int sum = 5;
  vector<vector<int>> output;
  vector<int> partial_output;
  subsequence(arr, 0, arr.size(), sum, partial_output, output);

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