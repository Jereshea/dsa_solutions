/******************************************************************************
Rod cutting problem

Given a rod of length ‘N’ units. The rod can be cut into different sizes and
each size has a cost associated with it. Determine the maximum cost obtained by
cutting the rod and selling its pieces.

Note:
1. The sizes will range from 1 to ‘N’ and will be integers.

2. The sum of the pieces cut should be equal to ‘N’.

3. Consider 1-based indexing.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= A[i] <= 100

Where ‘T’ is the total number of test cases, ‘N’ denotes the length of the rod,
and A[i] is the cost of sub-length.

Time limit: 1 sec.
Sample Input 1:
2
5
2 5 7 8 10
8
3 5 8 9 10 17 17 20
Sample Output 1:
12
24
Explanation of sample input 1:
Test case 1:

All possible partitions are:
1,1,1,1,1           max_cost=(2+2+2+2+2)=10
1,1,1,2             max_cost=(2+2+2+5)=11
1,1,3               max_cost=(2+2+7)=11
1,4                 max_cost=(2+8)=10
5                   max_cost=(10)=10
2,3                 max_cost=(5+7)=12
1,2,2               max _cost=(1+5+5)=12

Clearly, if we cut the rod into lengths 1,2,2, or 2,3, we get the maximum cost
which is 12.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
// Recursion
int length_find(vector<int> &price, int n, int remaining_length,int index){

    if(remaining_length==0){
        return 0;
    }

    if(index>=price.size()){
        return INT_MIN;
    }


    if(remaining_length<=0){
        return INT_MIN;
    }

    // Example prices={2,3} n=3
    // 2 3  length=3
    // 2+   length=3-(1)=2
    // 2+(2+) length=2-(1)=2
    // 2+(2+(2+)) length=2-(1)=1
    // 2+(2+(2+(0)))  length=
    int cost;
    int
include=price[index]+length_find(price,n,remaining_length-(index+1),index);
    if(include!=INT_MAX){
        cost=include;
    }
    int exclude=0+length_find(price,n,remaining_length,index+1);
    return max(cost,exclude);
}
int cutRod(vector<int> &price, int n)
{
        // Write your code here.
        return length_find(price, n, n,0);
}
*/

// Memoization
int length_find(vector<int> &price, int n, int remaining_length, int index,
                vector<vector<int>> &dp_array) {

  if (remaining_length == 0) {
    return 0;
  }

  if (index >= price.size()) {
    return INT_MIN;
  }

  if (remaining_length <= 0) {
    return INT_MIN;
  }

  if (dp_array[remaining_length][index] != INT_MIN) {
    return dp_array[remaining_length][index];
  }

  int cost;
  int include =
      price[index] +
      length_find(price, n, remaining_length - (index + 1), index, dp_array);
  if (include != INT_MAX) {
    cost = include;
  }
  int exclude =
      0 + length_find(price, n, remaining_length, index + 1, dp_array);
  return dp_array[remaining_length][index] = max(cost, exclude);
}
int cutRod(vector<int> &price, int n) {
  // Write your code here.
  vector<vector<int>> dp_array(n + 1, vector<int>(price.size(), INT_MIN));
  return length_find(price, n, n, 0, dp_array);
}
int main() {
  cout << "Rod cutting problem" << endl;
  int n = 5;
  vector<int> price = {2, 5, 7, 8, 10};
  cout << cutRod(price, n);

  return 0;
}