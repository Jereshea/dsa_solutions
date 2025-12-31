/******************************************************************************
Best Time to Buy and Sell Stock with Cooldown:

Problem statement
You are given a list of stock prices of size 'n' called ‘prices’, where
‘prices[i]’ represents the price on ‘i’th day.



Your task is to calculate the maximum profit you can earn by trading stocks if
you can only hold one stock at a time.



After you sell your stock on the ‘i’th day, you can only buy another stock on ‘i
+ 2’ th day or later.



Example:
Input: 'prices' = [4, 9, 0, 4, 10]

Output: 11

Explanation:
You are given prices = [4, 9, 0, 4, 10]. To get maximum profits you will have to
buy on day 0 and sell on day 1 to make a profit of 5, and then you have to buy
on day 3  and sell on day 4 to make the total profit of 11. Hence the maximum
profit is 11.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
// Recusrion
int stock_buy_sell(vector<int> &prices, int n, int index, int buy){
    if(index>=n){
        return 0;
    }

    if(buy==1){
        return max(-prices[index]+stock_buy_sell(prices,
n,index+1,0),stock_buy_sell(prices, n,index+1,1)); }else{ return
max(prices[index]+stock_buy_sell(prices, n,index+2,1),stock_buy_sell(prices,
n,index+1,0));
    }
}
int stockProfit(vector<int> &prices){
    // Write your code here.

    return stock_buy_sell(prices, prices.size(),0,1);
}
*/

/*
// Memoization
int stock_buy_sell(vector<int> &prices, int n, int index, int
buy,vector<vector<int>> &dp_array){ if(index>=n){ return 0;
    }
    if(dp_array[index][buy]!=INT_MIN){
        return dp_array[index][buy];
    }
    if(buy==1){
        return dp_array[index][buy]=max(-prices[index]+stock_buy_sell(prices,
n,index+1,0,dp_array),stock_buy_sell(prices, n,index+1,1,dp_array)); }else{
        return dp_array[index][buy]=max(prices[index]+stock_buy_sell(prices,
n,index+2,1,dp_array),stock_buy_sell(prices, n,index+1,0,dp_array));
    }
}
int stockProfit(vector<int> &prices){
    // Write your code here.
    vector<vector<int>> dp_array(prices.size(),vector<int>(2,INT_MIN));
    return stock_buy_sell(prices, prices.size(),0,1,dp_array);
}
*/

// Tabulation
int stock_buy_sell(vector<int> &prices, int n, int index, int buy,
                   vector<vector<int>> &dp_array) {

  dp_array[n][0] = 0;
  dp_array[n][1] = 0;
  dp_array[n + 1][0] = 0;
  dp_array[n + 1][1] = 0;

  for (int i = n - 1; i >= 0; i--) {
    for (int buy = 0; buy <= 1; buy++) {
      if (buy == 1) {
        dp_array[i][buy] =
            max(-prices[i] + dp_array[i + 1][0], dp_array[i + 1][1]);
      } else {
        dp_array[i][buy] =
            max(prices[i] + dp_array[i + 2][1], dp_array[i + 1][0]);
      }
    }
  }
  return dp_array[0][1];
}
int stockProfit(vector<int> &prices) {
  // Write your code here.
  vector<vector<int>> dp_array(prices.size() + 2, vector<int>(2, INT_MIN));
  return stock_buy_sell(prices, prices.size(), 0, 1, dp_array);
}
int main() {
  cout << "Best Time to Buy and Sell Stock with Cooldown" << endl;
  vector<int> prices = {4, 9, 0, 4, 10};
  cout << stockProfit(prices);
  return 0;
}