/******************************************************************************

Dynamic Programming (Method: Recursion + Memoization)
Fibonacci Series

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int fibonacci_series(vector<int> &dp_array, int n) {
  if (n == 0 || n == 1) {
    return n;
  }

  if (dp_array[n] != -1) {
    return dp_array[n];
  }
  // Step:2 Recursion + Memoization
  dp_array[n] =
      fibonacci_series(dp_array, n - 1) + fibonacci_series(dp_array, n - 2);

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