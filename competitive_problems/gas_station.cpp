/******************************************************************************

Gas Station:

There are n gas stations along a circular route, where the amount of gas at the
ith station is gas[i]. You have a car with an unlimited gas tank and it costs
cost[i] of gas to travel from the ith station to its next (i + 1)th station. You
begin the journey with an empty tank at one of the gas stations. Given two
integer arrays gas and cost, return the starting gas station's index if you can
travel around the circuit once in the clockwise direction, otherwise return -1.
If there exists a solution, it is guaranteed to be unique.

Example 1:
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 =
4 Travel to station 4. Your tank = 4 - 1 + 5 = 8 Travel to station 0. Your tank
= 8 - 2 + 1 = 7 Travel to station 1. Your tank = 7 - 3 + 2 = 6 Travel to
station 2. Your tank = 6 - 4 + 3 = 5 Travel to station 3. The cost is 5. Your
gas is just enough to travel back to station 3. Therefore, return 3 as the
starting index.


Approch:
Traverse the entire gas_stations once.
For every iteration, track the balance_gas available and the defecit
Every time we meet the deficit, increment the start by 1
In the end, if balance_gas>=defecit, then return the last updated start.

| i | gas[i] | cost[i] | balance | deficit | start |
| - | ------ | ------- | ------- | ------- | ----- |
| 0 | 1      | 3       | -2      | 2       | 1     |
| 1 | 2      | 4       | -2      | 4       | 2     |
| 2 | 3      | 5       | -2      | 6       | 3     |
| 3 | 4      | 1       | 3       | 6       | 3     |
| 4 | 5      | 2       | 6       | 6       | 3     |

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int gas_station(vector<int> &gas, vector<int> &cost) {
  int balance = 0;
  int defecit = 0;
  int start = 0;
  for (int i = 0; i < gas.size(); i++) {
    balance += gas[i] - cost[i];

    if (balance < 0) {
      defecit += abs(balance);
      balance = 0;
      start++;
    }
  }

  if (balance >= defecit) {
    return start;
  } else {
    return -1;
  }
}
int main() {
  cout << "Gas Station" << endl;
  vector<int> gas = {1, 2, 3, 4, 5};
  vector<int> cost = {3, 4, 5, 1, 2};
  cout << gas_station(gas, cost) << endl;

  return 0;
}