/******************************************************************************

Dynamic Programming
Max cut Rod lengths

rods = {7,2,5}
length=7

Output: 2

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int max_rods(vector<int> &rods, vector<int> &dp_array, int length) {
  if (length == 0) {
    return length;
  }

  if (length < 0) {
    return INT_MIN;
  }

  if (dp_array[length] != INT_MIN) {
    return dp_array[length];
  }

  for (int i = 0; i < rods.size(); i++) {
    int ans = max_rods(rods, dp_array, length - rods[i]);
    if (ans != INT_MIN) {
      dp_array[length] = max(dp_array[length], 1 + ans);
    }
  }

  return dp_array[length];
}

int main() {
  cout << "Max cut Rod lengths" << endl;
  vector<int> rods = {7, 2, 5};
  int length = 7;

  int n = rods.size();

  // Step:1 Create a dp_array/hash map
  vector<int> dp_array(length + 1, INT_MIN);
  dp_array[0] = 0;

  if (max_rods(rods, dp_array, length) == INT_MIN) {
    cout << "0" << endl;
  } else {
    cout << max_rods(rods, dp_array, length);
  }

  return 0;
}