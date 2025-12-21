/******************************************************************************

Dynamic Programming
Min available coins

coins = {1,2,5}
amount=7

1   2   5
1
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int min_coins(vector<int> &coins, vector<int> &dp_array, int amount) {
  if (amount == 0) {
    return amount;
  }

  if (amount < 0) {
    return INT_MAX;
  }

  if (dp_array[amount] != INT_MAX) {
    return dp_array[amount];
  }

  for (int i = 0; i < coins.size(); i++) {
    int ans = min_coins(coins, dp_array, amount - coins[i]);
    if (ans != INT_MAX) {
      dp_array[amount] = min(dp_array[amount], 1 + ans);
    }
  }

  return dp_array[amount];
}

int main() {
  cout << "Min available coins" << endl;
  vector<int> coins = {1, 2, 5};
  int amount = 7;

  int n = coins.size();

  // Step:1 Create a dp_array/hash map
  vector<int> dp_array(amount + 1, INT_MAX);
  dp_array[0] = 0;

  cout << min_coins(coins, dp_array, amount);

  return 0;
}