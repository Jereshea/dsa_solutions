/******************************************************************************
Count Subsequences:
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

long long find_increasing_subsequence(long long *arr, int n,
                                      vector<long long> &count) {

  vector<int> dp(n, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[i] < arr[j] && dp[i] < 1 + dp[j]) {
        dp[i] = 1 + dp[j];
        count[i] = dp[i];
      } else if (dp[i] == 1 + dp[j]) {
        count[i] = dp[i] + count[i];
      }
    }
  }
  cout << endl;
  // cout<<count.size();
  for (auto &m : count) {
    cout << m << " ";
  }

  return 0;
}
long long getInversions(long long *arr, int n) {
  // Write your code here.
  // Increasing Subsequence of length2
  vector<long long> count(n, 0);
  find_increasing_subsequence(arr, n, count);

  return 0;
}

int main() {
  cout << "Count Inversions";
  long long arr[] = {3, 2, 1, 5};
  long long n = sizeof(arr) / sizeof(arr[0]);
  getInversions(arr, n);

  return 0;
}