/******************************************************************************
Best Time to Buy and Sell Stock II:

You have been given stock values/prices for N number of days. Every i-th day
signifies the price of a stock on that day. Your task is to find the maximum
profit which you can make by buying and selling the stocks.

Note :
You may make as many transactions as you want but can not have more than one
transaction at a time i.e, if you have the stock, you need to sell it first, and
then only you can buy it again.

Sample Input 1 :
1
7
1 2 3 4 5 6 7
Sample Output 1 :
6
Explanation :
We can make the maximum profit by buying the stock on the first day and selling
it on the last day.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
// Recursion
long possibilities(long *values, int n, int index,int buy){
    if(index==n){
        return 0;
    }

    if(buy){
        return max(-values[index]+(possibilities(values, n,
index+1,0)),possibilities(values, n, index+1,1)); }else{ return
max(values[index]+(possibilities(values, n, index+1,1)),(possibilities(values,
n, index+1,0)));
    }
}

long getMaximumProfit(long *values, int n)
{
    //Write your code here
    return possibilities(values,n,0,1);
}
*/

/*
// Memoization
long possibilities(long *values, int n, int index,int buy,vector<vector<long>>
&dp_array){ if(index==n){ return 0;
    }

    if(dp_array[index][buy]!=INT_MIN){
        return dp_array[index][buy];
    }
    if(buy){
        return dp_array[index][buy]=max(-values[index]+(possibilities(values, n,
index+1,0,dp_array)),possibilities(values, n, index+1,1,dp_array)); }else{
        return dp_array[index][buy]=max(values[index]+(possibilities(values, n,
index+1,1,dp_array)),(possibilities(values, n, index+1,0,dp_array)));
    }

}

long getMaximumProfit(long *values, int n)
{
    //Write your code here
    vector<vector<long>> dp_array(n,vector<long>(2,INT_MIN));
    return possibilities(values,n,0,1,dp_array);
}
*/

// Tabulation
long possibilities(long *values, int n, int index, int buy,
                   vector<vector<long>> &dp_array) {
  dp_array[n][0] = 0;
  dp_array[n][1] = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < 2; j++) {
      if (j == 1) {
        dp_array[i][j] =
            max(-values[i] + dp_array[i + 1][0], dp_array[i + 1][1]);
      } else {
        dp_array[i][j] =
            max(values[i] + dp_array[i + 1][1], dp_array[i + 1][0]);
      }
    }
  }
  return dp_array[0][1];
}

long getMaximumProfit(long *values, int n) {
  // Write your code here
  vector<vector<long>> dp_array(n + 1, vector<long>(2, INT_MIN));
  return possibilities(values, n, 0, 1, dp_array);
}
int main() {
  cout << "Best Time to Buy and Sell Stock II" << endl;
  int n = 7;
  vector<long> values = {1, 2, 3, 4, 5, 6, 7};
  cout << getMaximumProfit(values.data(), n);
  return 0;
}