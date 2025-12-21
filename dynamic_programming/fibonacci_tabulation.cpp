/******************************************************************************

Dynamic Programming (Method: Tabulation)
Fibonacci Series

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int fibonacci_series(vector<int> &dp_array, int n) {
  if (n == 0 || n == 1) {
    return n;
  }

  dp_array[0] = 0;
  dp_array[1] = 1;

  // Step:2 Tabulation
  for (int i = 2; i <= n; i++) {
    dp_array[i] = dp_array[i - 1] + dp_array[i - 2];
  }

  return dp_array[n];
}
int main() {
  cout << "Fibonacci Series" << endl;
  int n = 6;

  // Step:1 Create a dp_array/hash map
  vector<int> dp_array(n + 1, -1);
  cout << fibonacci_series(dp_array, n);

  return 0;
}