/******************************************************************************
Count Subsets with Sum K:

You are given an array 'arr' of size 'n' containing positive integers and a
target sum 'k'.



Find the number of ways of selecting the elements from the array such that the
sum of chosen elements is equal to the target 'k'.



Since the number of ways can be very large, print it modulo 10 ^ 9 + 7.



Example:
Input: 'arr' = [1, 1, 4, 5]

Output: 3

Explanation: The possible ways are:
[1, 4]
[1, 4]
[5]
Hence the output will be 3. Please note that both 1 present in 'arr' are treated
differently.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
// Recursion
int min_difference(vector<int> &arr, int n, int k,int index, int curr_sum){
    if(curr_sum==k){
        return 1;
    }

    if(curr_sum>k){
        return 0;
    }

    if(index==n){
        return 0;
    }

    int include=min_difference(arr, n, k,index+1, curr_sum+arr[index]);
    int exclude=min_difference(arr, n, k,index+1, curr_sum);
    // cout<<"Include: "<<include<<endl;
    // cout<<"Exclude: "<<exclude<<endl;
    int ans=include+exclude;

    return ans;
}

int count_subset(vector<int> &arr, int k){
    int n=arr.size();
    int curr_sum=0;
    return min_difference(arr,n,k,0, curr_sum);
}
*/

// Memoization
int min_difference(vector<int> &arr, int n, int k, int index, int curr_sum,
                   vector<vector<int>> &dp_array) {
  if (curr_sum == k) {
    return 1;
  }
  if (curr_sum > k) {
    return 0;
  }
  if (index == n) {
    return 0;
  }

  if (dp_array[index][curr_sum] != -1) {
    return dp_array[index][curr_sum];
  }
  int include =
      min_difference(arr, n, k, index + 1, curr_sum + arr[index], dp_array);
  int exclude = min_difference(arr, n, k, index + 1, curr_sum, dp_array);
  // cout<<"Include: "<<include<<endl;
  // cout<<"Exclude: "<<exclude<<endl;
  dp_array[index][curr_sum] = include + exclude;

  return dp_array[index][curr_sum];
}

int count_subset(vector<int> &arr, int k) {
  int n = arr.size();
  int curr_sum = 0;
  vector<vector<int>> dp_array(n, vector<int>(k + 1, -1));
  return min_difference(arr, n, k, 0, curr_sum, dp_array);
}

int main() {
  cout << "Count Subsets with Sum K" << endl;
  vector<int> arr = {1, 4, 4, 5};
  int k = 5;
  cout << count_subset(arr, k);

  return 0;
}