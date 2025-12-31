/******************************************************************************
Print Longest Increasing Subsequence:

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
5 11 16
Explanation of Sample Input 1:
Length of longest subsequence is 3 i.e. [5, 11, 16] or [4, 11, 16].
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> longestIncreasingSubsequence(int arr[], int n) {
  // // Write Your Code here
  vector<int> output(n, 1), hash(n);

  // To print
  for (int i = 0; i < n; i++) {
    hash[i] = i;
  }

  // for(auto &m:hash){
  //     cout<<m<<" ";
  // }
  cout << endl;

  for (int i = 1; i < n; i++) {
    int maxi_length = output[i];
    int ind_1 = hash[i];
    for (int j = 0; j < i; j++) {
      if (arr[i] > arr[j]) {
        if (output[i] < 1 + output[j]) {
          output[i] = 1 + output[j];
          hash[i] = j;
        }
      }
    }
  }

  // for(auto &m:output){
  //     cout<<m<<" ";
  // }
  // cout<<endl;

  // for(auto &m:hash){
  //     cout<<m<<" ";
  // }
  // cout<<endl;

  // Get the longest subsequence length
  int result_len = 1;
  int index = 0;
  for (int i = 0; i < n; i++) {
    if (result_len < output[i]) {
      result_len = max(result_len, output[i]);
      index = i;
    }
  }

  vector<int> result;
  while (hash[index] != -1) {
    // cout<<arr[index]<<" "; // index=4
    result.push_back(arr[index]);
    int temp = index;
    index = hash[index]; // index=3
    hash[temp] = -1;
  }
  // cout<<endl;
  reverse(result.begin(), result.end());
  return result;
}

int main() {
  cout << "Longest Increasing Subsequence" << endl;
  int n = 6;
  int arr[n] = {5, 4, 11, 1, 16, 8};

  vector<int> result = longestIncreasingSubsequence(arr, n);
  for (auto &m : result) {
    cout << m << " ";
  }
  cout << endl;

  return 0;
}