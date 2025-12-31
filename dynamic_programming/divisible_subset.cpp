/******************************************************************************
Divisible Set:

You are given an array of distinct numbers ‘arr’ of size 'n'.



Your task is to return the largest subset of numbers from ‘arr’, such that any
pair of numbers ‘a’ and ‘b’ from the subset satisfies the following: a % b == 0
or b % a == 0.



A subset is nothing but any possible combination of the original array



Example:
Input: ‘arr’ = [1, 16, 7, 8, 4]

Output: [1, 4, 8, 16].

Explanation: In the set {1, 4, 8, 16}, you can take any pair from the set, and
either one of the elements from the pair will divide the other.

There are other possible sets, but this is the largest one.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
3
1 2 5
Sample Output 1 :
 Correct
Explanation of sample input 1:
The sets {1, 2} or {1, 5} are the two largest sets that satisfy the given
condition.

Hence either of them could be the answer.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> divisibleSet(vector<int> &arr) {
  // Write your code here.
  // Sort the array
  sort(arr.begin(), arr.end());
  int n = arr.size();
  vector<int> dp(n, 1), hash(n);

  for (int i = 0; i < n; i++) {
    hash[i] = i;
  }

  for (int i = 0; i < n; i++) {
    for (int prev = 0; prev < i; prev++) {
      if (arr[i] % arr[prev] == 0 && dp[i] < 1 + dp[prev]) {
        dp[i] = 1 + dp[prev];
        hash[i] = prev;
      }
    }
  }

  // for(auto &m:dp){
  //     cout<<m<<" ";
  // }
  // cout<<endl;

  // for(auto &m:hash){
  //     cout<<m<<" ";
  // }
  // cout<<endl;

  int longest_length = 1;
  int index = 0;
  for (int i = 0; i < dp.size(); i++) {
    if (dp[i] > longest_length) {
      longest_length = dp[i];
      index = i;
    }
  }

  vector<int> result;
  while (hash[index] != index) {
    result.push_back(arr[index]);
    index = hash[index];
  }
  result.push_back(arr[index]);
  // for(auto &m:result){
  //     cout<<m<<" ";
  // }
  return result;
}
int main() {
  cout << "Divisible Set" << endl;
  vector<int> arr = {1, 2, 5};
  vector<int> result = divisibleSet(arr);
  for (auto &m : result) {
    cout << m << " ";
  }

  return 0;
}