/*********
House robber

A robber is targeting to rob houses from a street. Each house has security
measures that alert the police when two adjacent houses are robbed. The houses
are arranged in a circular manner, thus the first and last houses are adjacent
to each other.



Given an integer array money, where money[i] represents the amount of money that
can be looted from the (i+1)th house. Return the maximum amount of money that
the robber can loot without alerting the police.


Example 1

Input: money = [2, 1, 4, 9]

Output: 10

Explanation:

[2, 1, 4, 9] The underlined houses would give the maximum loot.

Note that we cannot loot the 1st and 4th houses together.

Example 2

Input: money = [1, 5, 2, 1, 6]

Output: 11

Explanation:

[1, 5, 2, 1, 6] The underlined houses would give the maximum loot.
***********/
#include <bits/stdc++.h>
using namespace std;

class Solution {

  /*
  // Recursion
  public:
      int houseRobber_Rec(vector<int>& money, int index, int size){
          if(index>=size){
              return 0;
          }

          int include=money[index]+houseRobber_Rec(money,index+2,size);
          int exclude=houseRobber_Rec(money,index+1,size);

          return max(include,exclude);
      }
      int houseRobber(vector<int>& money) {
          if(money.size()==0){
              return 0;
          }else if(money.size()==1){
              return money[0];
          }else{
              int include_first_house= houseRobber_Rec(money,0,money.size()-1);
              int include_last_house= houseRobber_Rec(money,1,money.size());

              return max(include_first_house, include_last_house);
          }


      }
  };
  */

public:
  int houseRobber_Rec(vector<int> &money, int index, int size,
                      vector<int> &dp) {
    if (index >= size) {
      return 0;
    }
    if (dp[index] != -1) {
      return dp[index];
    }

    int include = money[index] + houseRobber_Rec(money, index + 2, size, dp);
    int exclude = houseRobber_Rec(money, index + 1, size, dp);

    return dp[index] = max(include, exclude);
  }
  int houseRobber(vector<int> &money) {
    if (money.size() == 0) {
      return 0;
    } else if (money.size() == 1) {
      return money[0];
    } else {
      vector<int> dp(money.size() + 1, -1);
      int include_first_house = houseRobber_Rec(money, 0, money.size() - 1, dp);
      vector<int> dp_2(money.size() + 1, -1);
      int include_last_house = houseRobber_Rec(money, 1, money.size(), dp_2);

      return max(include_first_house, include_last_house);
    }
  }
};

int main() {
  // your code goes here
  cout << "House robber" << endl;
  vector<int> money = {1, 5, 2, 1, 6};
  Solution sol;
  cout << sol.houseRobber(money);
}
