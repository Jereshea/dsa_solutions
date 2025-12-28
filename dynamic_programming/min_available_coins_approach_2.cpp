/******************************************************************************

Dynamic Programming
Min available coins

coins = {1,2,5}
amount=7

Ouput: 2 [2,5]
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  /*
      int subset_coin_change(vector<int>& coins, int n, int index, int amount){

          if(index==0){
              if(amount%coins[index]==0){
                  return amount/coins[index];
              }else{
                  return INT_MAX;
              }
          }

          if(amount<0){
              return INT_MAX;
          }

          int ans=INT_MAX;
          int include;
          int exclude=subset_coin_change(coins, n, index-1, amount);
          if(coins[index]<=amount){
              int include=subset_coin_change(coins, n, index,
     amount-coins[index]); if(include!=INT_MAX){ ans=1+include;
              }
          }

          return min(ans,exclude);
      }
      int coinChange(vector<int>& coins, int amount) {
          int n=coins.size();
          return subset_coin_change(coins, n, n-1, amount);
      }
  */

  int subset_coin_change(vector<int> &coins, int n, int index, int amount,
                         vector<vector<int>> &dp_array) {

    if (index == 0) {
      if (amount % coins[index] == 0) {
        return amount / coins[index];
      } else {
        return INT_MAX;
      }
    }

    if (dp_array[index][amount] != -1) {
      return dp_array[index][amount];
    }
    if (amount < 0) {
      return INT_MAX;
    }

    int ans = INT_MAX;
    int include;
    int exclude = subset_coin_change(coins, n, index - 1, amount, dp_array);
    if (coins[index] <= amount) {
      int include =
          subset_coin_change(coins, n, index, amount - coins[index], dp_array);
      if (include != INT_MAX) {
        ans = 1 + include;
      }
    }

    return dp_array[index][amount] = min(ans, exclude);
  }
  int coinChange(vector<int> &coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp_array(n, vector<int>(amount + 1, -1));
    return subset_coin_change(coins, n, n - 1, amount, dp_array);
  }
};

int main() {
  cout << "Min available coins" << endl;
  vector<int> coins = {1, 2, 5};
  int amount = 7;
  Solution sol;
  cout << sol.coinChange(coins, amount);

  return 0;
}