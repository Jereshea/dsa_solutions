/******************************************************************************
Best Time to Buy and Sell Stock:

You are given an array/list 'prices' where the elements of the array represent
the prices of the stock as they were yesterday and indices of the array
represent minutes. Your task is to find and return the maximum profit you can
make by buying and selling the stock. You can buy and sell the stock only once.

Note:

You can’t sell without buying first.
For Example:
For the given array [ 2, 100, 150, 120],
The maximum profit can be achieved by buying the stock at minute 0 when its
price is Rs. 2 and selling it at minute 2 when its price is Rs. 150. So, the
output will be 148. Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
2 <= N <= 10^4
1 <= ARR[i] <= 10^9

Time Limit: 1 sec.
Sample Input 1:
2
4
1 2 3 4
4
2 2 2 2
Sample Output 1:
3
0
Explanation For Sample Output 1:
For the first test case, it’s optimal to buy the stock at minute 0 and sell it
at minute 3 to get a maximum profit of 3.

For the second test case, the maximum profit will be 0 for all possible ways of
buying and selling stock.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices) {
  // Write your code here.
  int min_buy = prices[0];
  int profit = INT_MIN;
  int curr_profit;
  for (int i = 1; i < prices.size(); i++) {
    curr_profit = prices[i] - min_buy;
    profit = max(profit, curr_profit);
    min_buy = min(min_buy, prices[i]);
  }

  if (profit < 0) {
    return 0;
  } else {
    return profit;
  }
}
int main() {
  cout << "Best Time to Buy and Sell Stock" << endl;
  vector<int> prices = {1, 2, 3, 4};
  cout << maximumProfit(prices);

  return 0;
}