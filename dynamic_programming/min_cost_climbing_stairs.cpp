/******************************************************************************

Dynamic Programming
Min Cost to Reach the Top Stairs

cost = {10, 15, 20}
index   0   1   2

Approch
1) Reach till min(n-1,n-2)
2) How to find the cost? cost[i]+min(i-1,i-2)

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int min_cost(vector<int> cost, vector<int> &dp_array, int stairs) {

  if (stairs == 1 || stairs == 0) {
    return cost[stairs];
  }

  if (dp_array[stairs] != -1) {
    return dp_array[stairs];
  }
  // Memoization
  dp_array[stairs] = cost[stairs] + min(min_cost(cost, dp_array, stairs - 1),
                                        min_cost(cost, dp_array, stairs - 2));
  return dp_array[stairs];
}

int main() {
  cout << "Min Cost to Reach the Top Stairs " << endl;
  vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

  int n = cost.size();

  // Step:1 Create a dp_array/hash map
  vector<int> dp_array(n, -1);
  cout << min(min_cost(cost, dp_array, n - 1), min_cost(cost, dp_array, n - 2));

  return 0;
}