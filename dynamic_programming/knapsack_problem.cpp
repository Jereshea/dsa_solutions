/******************************************************************************
0 1 Knapsack:

A thief is robbing a store and can carry a maximal weight of W into his
knapsack. There are N items and the ith item weighs wi and is of value vi.
Considering the constraints of the maximum weight that a knapsack can carry, you
have to find and return the maximum value that a thief can generate by stealing
items.

Sample Input:
1
4
1 2 4 5
5 4 8 6
5
Sample Output:
13
*******************************************************************************/

#include <bits/stdc++.h>
// #define MOD -10e9
using namespace std;

/*
// Recursion
int subset(vector<int> weight, vector<int> value, int n, int index, int
currWeight, int maxWeight){ if(currWeight > maxWeight){ return 0;
    }
    if(index==0){
        if(currWeight+weight[index]<=maxWeight){
            return value[index];
        }else{
            return 0;
        }
    }

    if(index<0){
        return 0;
    }
    int include=INT_MIN;
    if(currWeight+weight[index]<=maxWeight){
        include=value[index]+subset(weight, value, n, index-1,
currWeight+weight[index], maxWeight);
    }
    int exclude=0+subset(weight, value, n, index-1, currWeight, maxWeight);

    return max(include, exclude);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
        return subset(weight, value, n, n-1, 0, maxWeight);
}
*/

// Memoization
int subset(vector<int> &weight, vector<int> &value, int n, int index,
           int currWeight, int maxWeight, vector<vector<int>> &dp_array) {

  if (dp_array[index][currWeight] != -1) {
    return dp_array[index][currWeight];
  }

  if (index == 0) {
    if (currWeight + weight[index] <= maxWeight) {
      return value[index];
    } else {
      return 0;
    }
  }

  if (index < 0) {
    return 0;
  }
  int include = 0;
  if (currWeight + weight[index] <= maxWeight) {
    include =
        value[index] + subset(weight, value, n, index - 1,
                              currWeight + weight[index], maxWeight, dp_array);
  }
  int exclude =
      0 + subset(weight, value, n, index - 1, currWeight, maxWeight, dp_array);

  return dp_array[index][currWeight] = max(include, exclude);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  vector<vector<int>> dp_array(n, vector<int>(maxWeight + 1, -1));
  return subset(weight, value, n, n - 1, 0, maxWeight, dp_array);
}

int main() {
  cout << "0 1 Knapsack" << endl;
  int n = 4;
  int maxWeight = 5;
  vector<int> weight = {1, 2, 4, 5};
  vector<int> value = {5, 4, 8, 6};

  cout << knapsack(weight, value, n, maxWeight);

  return 0;
}