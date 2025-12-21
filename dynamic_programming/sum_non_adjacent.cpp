/******************************************************************************

Dynamic Programming
Maximum sum of Non-Adjacent elements

Input: arr[] = [5, 5, 10, 100, 10, 5]
Output: 110

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int max_sum(vector<int> &arr, vector<int> &dp_array, int start, int n) {
  if (start >= n) {
    return 0;
  }

  if (dp_array[start] != INT_MIN) {
    return dp_array[start];
  }

  int include = arr[start] + max_sum(arr, dp_array, start + 2, n);
  int exclude = 0 + max_sum(arr, dp_array, start + 1, n);
  dp_array[start] = max(include, exclude);
  return dp_array[start];
}

int main() {
  cout << "Maximum sum of Non-Adjacent elements" << endl;
  vector<int> arr = {5, 5, 10, 100, 10, 5};

  int n = arr.size();

  // Step:1 Create a dp_array/hash map
  vector<int> dp_array(n, INT_MIN);
  cout << max_sum(arr, dp_array, 0, n);

  return 0;
}