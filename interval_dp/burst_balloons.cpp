/******************************************************************************

Burst Balloons

You are given an array 'arr' of 'n' balloons, where 'a[i]' represents the coins
associated with 'ith' balloon.



On bursting 'ith' balloon, the number of coins collected is equal to 'a[i-1] *
a[i] * a[i+1]'. Also, balloons 'i-1' and 'i+1' now become adjacent.



Find the maximum possible coins collected after bursting all the balloons.
Assume an extra 1 at each boundary.



Example:
Input: 'arr' = [5,2,6,9]

Output: 384

Explanation:
The best way to burst balloons is following:
Choosing 2nd balloon, we get 5*2*6 coins. Now the array is [5,6,9].
Choosing 2nd balloon, we get 5*6*9 coins. Now the array is [5,9].
Choosing 1st balloon, we get 1*5*9 coins. Now the array is [9].
Choosing the last balloon, we get 1*9*1 coins.
Finally we get 5*2*6 + 5*6*9 + 1*5*9 + 1*9*1 = 384 coins.
There's no way to choose the order of bursting balloons such that we get more
than 384 coins.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
2
5 10


Sample Output 1:
60


Explanation of Sample Input 1:
For the given input, best way to burst balloons is as follows:
First burst the 1st balloon collecting coins = 1*5*10. Now the array becomes
[10]. Then burst the last remaining balloon collecting coins = 1*10*1. Finally
total number of coins collected = 1*5*10 + 1*10*10 = 60.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
// Recursion
int burst_balloons_interval_dp(vector<int> &arr, int start, int end){
    if(start>end){
        return 0;
    }

    int result=INT_MIN;
    for(int i=start;i<=end;i++){
        int
cost=arr[start-1]*arr[i]*arr[end+1]+burst_balloons_interval_dp(arr,start,
i-1)+burst_balloons_interval_dp(arr,i+1, end); result=max(cost,result);
    }

    return result;
}
int burstBalloons(vector<int> &arr){
    // Write your code here.
    arr.insert(arr.begin(),1);
    arr.push_back(1);
    // 1 5 2 6 9 1
    return burst_balloons_interval_dp(arr,1, arr.size()-1);
}
*/

int burst_balloons_interval_dp(vector<int> &arr, int start, int end,
                               vector<vector<int>> &dp_array) {
  if (start > end) {
    return 0;
  }

  if (dp_array[start][end] != INT_MIN) {
    return dp_array[start][end];
  }
  int result = INT_MIN;
  for (int i = start; i <= end; i++) {
    int cost = arr[start - 1] * arr[i] * arr[end + 1] +
               burst_balloons_interval_dp(arr, start, i - 1, dp_array) +
               burst_balloons_interval_dp(arr, i + 1, end, dp_array);
    result = max(cost, result);
  }

  return dp_array[start][end] = result;
}
int burstBalloons(vector<int> &arr) {
  // Write your code here.
  arr.insert(arr.begin(), 1);
  arr.push_back(1);
  // 1 5 2 6 9 1
  vector<vector<int>> dp_array(arr.size() + 1,
                               vector<int>(arr.size() + 1, INT_MIN));
  return burst_balloons_interval_dp(arr, 1, arr.size() - 1, dp_array);
}

int main() {
  cout << "Burst Balloons" << endl;
  vector<int> arr = {5, 2, 6, 9};
  cout << burstBalloons(arr);

  return 0;
}