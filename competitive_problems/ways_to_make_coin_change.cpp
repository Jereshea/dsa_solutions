/************
Ways To Make Coin Change
Moderate
80/80
Average time to solve is 20m
Contributed by
207 upvotes
Asked in companies
Problem statement
You are given an infinite supply of coins of each of denominations D = {D0, D1,
D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in
which you can make a change for value V using coins of denominations from D.
Print 0, if a change isn't possible.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
3
1 2 3
4
Sample Output 1:
4
Explanation for Sample Output 1:
We can make a change for the value V = 4 in four ways.
1. (1,1,1,1),
2. (1,1, 2), [One thing to note here is, (1, 1, 2) is same as that of (2, 1, 1)
and (1, 2, 1)]
3. (1, 3), and
4. (2, 2)
Sample Input 2 :
3
5 3 2
1
Sample Output 2:
0

*************/
#include <bits/stdc++.h>
using namespace std;

long long count_ways(int *denominations, int start, int n, int value,
                     vector<vector<long long>> &dp_array) {

  if (value == 0) {
    return 1;
  }

  if (value < 0) {
    return 0;
  }
  if (start == n) {
    return 0;
  }

  if (dp_array[start][value] != -1) {
    return dp_array[start][value];
  }

  long long include = count_ways(denominations, start, n,
                                 value - denominations[start], dp_array);
  long long exclude = count_ways(denominations, start + 1, n, value, dp_array);

  return dp_array[start][value] = include + exclude;
}

long countWaysToMakeChange(int *denominations, int n, int value) {
  // Write your code here
  vector<vector<long long>> dp_array(n, vector<long long>(value + 1, -1));
  return count_ways(denominations, 0, n, value, dp_array);
}
int main() {
  int n = 3;
  int denominations[n] = {1, 2, 3};
  int value = 4;
  cout << countWaysToMakeChange(denominations, n, value);
  return 0;
}