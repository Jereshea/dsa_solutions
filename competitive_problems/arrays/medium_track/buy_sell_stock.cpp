/******************************************************************************

Best time to buy and sell stock

Given an array arr of n integers, where arr[i] represents price of the stock on
the ith day. Determine the maximum profit achievable by buying and selling the
stock at most once.



The stock should be purchased before selling it, and both actions cannot occur
on the same day.


Example 1

Input: arr = [10, 7, 5, 8, 11, 9]

Output: 6

Explanation: Buy on day 3 (price = 5) and sell on day 5 (price = 11), profit =
11 - 5 = 6.

Example 2

Input: arr = [5, 4, 3, 2, 1]

Output: 0

Explanation: In this case, no transactions are made. Therefore, the maximum
profit remains 0.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int stockBuySell(vector<int> arr, int n) {
    int profit = 0;

    int min_buy = arr[0];
    int max_sell = INT_MIN;

    for (int i = 1; i < arr.size(); i++) {
      int profit = arr[i] - min_buy;
      max_sell = max(max_sell, profit);
      min_buy = min(min_buy, arr[i]);
    }
    if (max_sell < 0) {
      return 0;
    }
    return max_sell;
  }
};

int main() {
  cout << "Best time to buy and sell stock" << endl;
  vector<int> arr = {10, 7, 5, 8, 11, 9};
  int n = arr.size();
  Solution sol;
  cout << sol.stockBuySell(arr, n);
  return 0;
}