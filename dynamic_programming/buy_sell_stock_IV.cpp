/******************************************************************************
Best Time to Buy and Sell Stock IV:

You have been given an array 'PRICES' consisting of 'N' integers where PRICES[i]
denotes the price of a given stock on the i-th day. You are also given an
integer 'K' denoting the number of possible transactions you can make.

Your task is to find the maximum profit in at most K transactions. A valid
transaction involves buying a stock and then selling it.

Note
You can’t engage in multiple transactions simultaneously, i.e. you must sell the
stock before rebuying it. For Example Input: N = 6 , PRICES = [3, 2, 6, 5, 0, 3]
and K = 2. Output: 7

Explanation : The optimal way to get maximum profit is to buy the stock on day
2(price = 2) and sell it on day 3(price = 6) and rebuy it on day 5(price = 0)
and sell it on day 6(price = 3). The maximum profit will be (6 - 2) + (3 - 0)
= 7. Detailed explanation ( Input/output format, Notes, Images ) Constraints 1
<= T <= 100 1 <= N <= 5000 0 <= K <= N/2 0 <= ARR[i] <=10^5

Time Limit : 1 sec
Sample Input 1
2
5 2
8 5 1 3 10
4 2
10 8 6 2
Sample Output 1
9
0
Explanation for Sample 1
Test Case 1: In this case, we can make a maximum of 2 transactions. The optimal
way to get maximum profit is to make only 1 transaction, i.e., buy the stock on
day 3 (price = 1) and sell it on day 5(price = 10). The profit will be 10 - 1
= 9.

Test Case 2: In the second test case, we can make a maximum of 2 transactions.
The optimal way to get maximum profit is to make 0 transactions because the
price of stock is continuously decreasing and we will have a loss if we buy and
sell the stock.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
// Recursion
int stock_buy_sell(vector<int> &prices, int n, int index, int buy,int k){

    if(k<=0){
        return 0;
    }
    if(index>=n){
        return 0;
    }

    if(buy==1){
        return max(-prices[index]+stock_buy_sell(prices,
n,index+1,0,k),stock_buy_sell(prices, n,index+1,1,k)); }else{ return
max(prices[index]+stock_buy_sell(prices, n,index+1,1,k-1),stock_buy_sell(prices,
n,index+1,0,k));
    }
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    return stock_buy_sell(prices, prices.size(),0,1,k);
}
*/

// Memoization
int stock_buy_sell(vector<int> &prices, int n, int index, int buy, int k,
                   vector<vector<vector<int>>> &dp_array) {
  if (k <= 0) {
    return 0;
  }
  if (index >= n) {
    return 0;
  }
  if (dp_array[index][buy][k] != INT_MIN) {
    return dp_array[index][buy][k];
  }
  if (buy == 1) {
    return dp_array[index][buy][k] =
               max(-prices[index] +
                       stock_buy_sell(prices, n, index + 1, 0, k, dp_array),
                   stock_buy_sell(prices, n, index + 1, 1, k, dp_array));
  } else {
    return dp_array[index][buy][k] =
               max(prices[index] +
                       stock_buy_sell(prices, n, index + 1, 1, k - 1, dp_array),
                   stock_buy_sell(prices, n, index + 1, 0, k, dp_array));
  }
}
int maximumProfit(vector<int> &prices, int n, int k) {
  // Write your code here.
  vector<vector<vector<int>>> dp_array(
      prices.size() + 1, vector<vector<int>>(2, vector<int>(k + 1, INT_MIN)));
  return stock_buy_sell(prices, prices.size(), 0, 1, k, dp_array);
}

int main() {
  cout << "Best Time to Buy and Sell Stock IV" << endl;
  vector<int> prices = {3, 2, 6, 5, 0, 3};
  int n = prices.size();
  int k = 2;
  cout << maximumProfit(prices, n, k);
  return 0;
}