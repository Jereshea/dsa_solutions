/******************************************************************************
Cost to Cut a Chocolate:

You are given chocolate of ‘N’ length. The chocolate is labeled from 0 to ‘N’.
You are also given an array ‘CUTS’ of size ‘C’, denoting the positions at which
you can do a cut. The order of cuts can be changed. The cost of one cut is the
length of the chocolate to be cut. Therefore, the total cost is the sum of all
the cuts. Print the minimum cost to cut the chocolate.

Note:

All the integers in the ‘CUTS’ array are distinct.
For example:
Let ‘N’ be: 4
Let the ‘CUTS’ array be: [1, 3].

Let the order of doing the cut be [1, 3].
The first cut of 1 on length 4 results in a cost of 4, and chocolate is split
into two parts of the length of 1 and 3. The second cut of 3 on length 3 results
in a cost of 3, and chocolate is split into two parts again of the length of 2
and 1. So the total cost is 7.

The cost will remain the same if we change the order of cutting. So the result
is 7. Detailed explanation ( Input/output format, Notes, Images ) Constraints :
1 <= T <= 10
2 <= N <= 10^5
1 <= C <= 10^3
1 <= CUTS[i] <= N - 1

Time Limit: 1 sec
Sample Input 1 :
2
4 2
1 3
5 3
1 3 4
Sample Output 1 :
7
10
Explanation For Sample Output 1 :
For test case 1:
Let the order of doing the cut be [1, 3].
The first cut of 1 on length 4 results in a cost of 4, and chocolate is split
into two parts of the length of 1 and 3. The second cut of 3 on length 3 results
in a cost of 3, and chocolate is split into two parts again of the length of 2
and 1. So the total cost is 7.

The cost will remain the same if we change the order of cutting. So the result
is 7.

For test case 2:
Let the order of doing the cut be [1, 3, 4].
The first cut of 1 on length 5 results in a cost of 5, and chocolate is split
into two parts of the length of 1 and 4. The second cut of 3 on length 4 results
in a cost of 4, and chocolate is split into two parts again of the length of 2
and 2. The total cost is 9. The third cut of 4 on length 2 results in a cost of
2, and chocolate is split into two parts again of the length of 1 and 1. The
total cost is 11.

The minimum cost will be 10 when the order of doing cuts will be: [3, 1, 4].
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
int cost_interval_dp(vector<int> &cuts, int n, int c, int start, int end){
    if(start>end){
        return 0;
    }
    int min_cost=INT_MAX;
    for(int i=start;i<=end;i++){
        int
cost=cuts[end+1]-cuts[start-1]+cost_interval_dp(cuts,n,c,start,i-1)+cost_interval_dp(cuts,n,c,i+1,end);
        min_cost=min(min_cost,cost);
    }

    return min_cost;
}
int cost(int n, int c, vector<int> &cuts){
    // Write your code here.
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    // 0 1 3 4
    // 0 1 2 3
    // 0 1 2 3 4
    return cost_interval_dp(cuts, n,c,1,c);
}
*/

int cost_interval_dp(vector<int> &cuts, int n, int c, int start, int end,
                     vector<vector<int>> &dp_array) {
  if (start > end) {
    return 0;
  }

  if (dp_array[start][end] != INT_MAX) {
    return dp_array[start][end];
  }

  int min_cost = INT_MAX;
  for (int i = start; i <= end; i++) {
    int cost = cuts[end + 1] - cuts[start - 1] +
               cost_interval_dp(cuts, n, c, start, i - 1, dp_array) +
               cost_interval_dp(cuts, n, c, i + 1, end, dp_array);
    min_cost = min(min_cost, cost);
  }

  return dp_array[start][end] = min_cost;
}
int cost(int n, int c, vector<int> &cuts) {
  // Write your code here.
  cuts.push_back(n);
  cuts.insert(cuts.begin(), 0);
  sort(cuts.begin(), cuts.end());
  vector<vector<int>> dp_array(cuts.size() + 1,
                               vector<int>(cuts.size() + 1, INT_MAX));
  return cost_interval_dp(cuts, n, c, 1, c, dp_array);
}

int main() {
  cout << "Cost to Cut a Chocolate" << endl;
  vector<int> cuts = {1, 3};
  int n = 4; // chocolate length
  int c = 2;
  cout << cost(n, c, cuts);

  return 0;
}