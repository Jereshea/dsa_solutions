/******************************************************************************
Longest Increasing Subsequence:

For a given array with N elements, you need to find the length of the longest
subsequence from the array such that all the elements of the subsequence are
sorted in strictly increasing order.

Strictly Increasing Sequence is when each term in the sequence is larger than
the preceding term.

For example:
[1, 2, 3, 4] is a strictly increasing array, while [2, 1, 4, 3] is not.

Sample Input :
6
5 4 11 1 16 8
Sample Output 1 :
3
Explanation of Sample Input 1:
Length of longest subsequence is 3 i.e. [5, 11, 16] or [4, 11, 16].
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
// Recursion
int longestIncreasingSubsequence_length(int arr[], int n, int index,int prev){
    if(index==n){
        return 0;
    }

    int include=0;
    if(prev==-1 || arr[index]>arr[prev]){
        include=1+longestIncreasingSubsequence_length(arr,n,index+1,index);
    }

    int exclude=0+longestIncreasingSubsequence_length(arr,n,index+1,prev);

    return max(include,exclude);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    return longestIncreasingSubsequence_length(arr,n,0,-1);
}
*/

/*
// Memoization
int longestIncreasingSubsequence_length(int arr[], int n, int index,int prev,
vector<vector<int>> &dp_array){ if(index==n){ return 0;
    }

    if(dp_array[index][prev+1]!=INT_MIN){
        return dp_array[index][prev+1];
    }

    int include=INT_MIN;
    if(prev==-1 || arr[index]>arr[prev]){
        include=1+longestIncreasingSubsequence_length(arr,n,index+1,index,dp_array);
    }

    int
exclude=0+longestIncreasingSubsequence_length(arr,n,index+1,prev,dp_array);

    return dp_array[index][prev+1]=max(include,exclude);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<vector<int>> dp_array(n,vector<int>(n+1,INT_MIN));
    return longestIncreasingSubsequence_length(arr,n,0,-1,dp_array);
}
*/

// Tabulation

int longestIncreasingSubsequence_length(int arr[], int n, int index, int prev,
                                        vector<vector<int>> &dp_array) {

  for (int i = 0; i <= n; i++) {
    dp_array[n][i] = 0;
  }

  for (int i = n - 1; i >= 0; i--) {
    for (int j = i - 1; j >= -1; j--) {
      int include = INT_MIN;
      if (j == -1 || arr[i] > arr[j]) {
        include = 1 + dp_array[i + 1][i + 1];
      }

      int exclude = 0 + dp_array[i + 1][j + 1];

      dp_array[i][j + 1] = max(include, exclude);
    }
  }

  return dp_array[0][0];
}
int longestIncreasingSubsequence(int arr[], int n) {
  // Write Your Code here
  vector<vector<int>> dp_array(n + 1, vector<int>(n + 1, INT_MIN));
  return longestIncreasingSubsequence_length(arr, n, 0, -1, dp_array);
}

int main() {
  cout << "Longest Increasing Subsequence" << endl;
  int n = 6;
  int arr[n] = {5, 4, 11, 1, 16, 8};
  cout << longestIncreasingSubsequence(arr, n);

  return 0;
}