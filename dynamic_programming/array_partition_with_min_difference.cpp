/************************************
You are given an array 'arr' containing 'n' non-negative integers.



Your task is to partition this array into two subsets such that the absolute
difference between subset sums is minimum.



You just need to find the minimum absolute difference considering any valid
division of the array elements.



Note:

1. Each array element should belong to exactly one of the subsets.

2. Subsets need not always be contiguous.
For example, for the array : [1, 2, 3], some of the possible divisions are
   a) {1,2} and {3}
   b) {1,3} and {2}.

3. Subset-sum is the sum of all the elements in that subset.
Example:
Input: 'n' = 5, 'arr' = [3, 1, 5, 2, 8].

Ouput: 1

Explanation: We can partition the given array into {3, 1, 5} and {2, 8}.
This will give us the minimum possible absolute difference i.e. (10 - 9 = 1).
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4
1 2 3 4
Sample Output 1:
0
Explanation for sample input 1:
We can partition the given array into {2,3} and {1,4}.
This will give us the minimum possible absolute difference i.e. (5 - 5 = 0) in
this case. Sample Input 2:
3
8 6 5
Sample Output 2:
3
Explanation for sample input 2:
We can partition the given array into {8} and {6,5}.
This will give us the minimum possible absolute difference i.e. (11 - 8 = 3).
Expected time complexity:
The expected time complexity is O(n * 𝚺 'arr'[i]), where 𝚺 'arr'[i] denotes the
sum of all elements in 'arr'. Constraints: 1 <= 'n' <= 10^3 0 <= 'arr'[i] <=
10^3 0 <= 𝚺 'arr'[i] <= 10^4,

where 𝚺 'arr'[i] denotes the sum of all elements in 'arr'.

Time Limit: 1sec
*******************************************/
#include <bits/stdc++.h>
using namespace std;

int min_difference(vector<int> &arr, int n, int index, int total_sum,
                   int curr_sum, int abs_min, vector<vector<int>> &dp_array) {
  if (index == n) {
    int subset_1 = curr_sum;
    int subset_2 = total_sum - curr_sum;
    return abs(subset_1 - subset_2);
  }

  if (dp_array[index][curr_sum] != INT_MAX) {
    return dp_array[index][curr_sum];
  }

  int include = min_difference(arr, n, index + 1, total_sum,
                               curr_sum + arr[index], abs_min, dp_array);
  int exclude =
      min_difference(arr, n, index + 1, total_sum, curr_sum, abs_min, dp_array);
  // cout<<"Include: "<<include<<endl;
  // cout<<"Exclude: "<<exclude<<endl;
  dp_array[index][curr_sum] = min(include, exclude);

  return dp_array[index][curr_sum];
}

int minSubsetSumDifference(vector<int> &arr, int n) {
  // Write your code here.
  int abs_min = INT_MAX;
  int total_sum = 0;
  int curr_sum = 0;
  for (int i = 0; i < n; i++) {
    total_sum += arr[i];
  }
  vector<vector<int>> dp_array(n, vector<int>(total_sum + 1, INT_MAX));
  return min_difference(arr, n, 0, total_sum, curr_sum, abs_min, dp_array);
}

int main() {
  int n = 3;
  vector<int> arr = {8, 6, 5};
  cout << minSubsetSumDifference(arr, n);

  return 0;
}