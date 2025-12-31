/******************************************************************************
Longest String Chain:

Problem statement
You are given an array 'arr' of strings, where each string consists of English
lowercase letters.



A string chain of 'arr' is defined as:

(1) A sequence of string formed using elements of 'arr'.

(2) Every string in the sequence can be formed by inserting a lowercase English
letter into the previous string (except the first string).



Find the length of the longest possible string chain of 'arr'.



Example :
Input: 'arr' = ["x", "xx", "y", "xyx"]

Output: 3

Explanation:
The longest possible string chain is “x” -> “xx” -> “xyx”.
The length of the given chain is 3, hence the answer is 3.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
3
m
nm
mmm


Expected Answer :
2


Output on console :
2


Explanation For Sample Input 1 :
In this testcase, the longest possible string chain is "m" -> "nm".
The length of the given chain is 2, hence the answer is 2.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

bool compare_strings(string &s1, string &s2) {
  if (s1.length() != s2.length() + 1) {
    return false;
  }

  int index_1 = 0;
  int index_2 = 0;

  while (index_1 < s1.length()) {
    if (index_2 < s2.length() && s1[index_1] == s2[index_2]) {
      index_1++;
      index_2++;
    } else {
      index_1++;
    }
  }

  if (index_1 == s1.length() && index_2 == s2.length()) {
    return true;
  } else {
    return false;
  }
}
int longest_string(vector<string> &arr) {
  int n = arr.size();
  vector<int> dp(n, 1);

  for (int i = 0; i < n; i++) {
    for (int prev = 0; prev < i; prev++) {
      if (compare_strings(arr[i], arr[prev]) && dp[i] < 1 + dp[prev]) {
        dp[i] = 1 + dp[prev];
      }
    }
  }

  int longest_length = 1;
  int index = 0;
  for (int i = 0; i < dp.size(); i++) {
    if (dp[i] > longest_length) {
      longest_length = dp[i];
      index = i;
    }
  }

  int length_output = 0;
  int result;
  for (int i = 0; i < dp.size(); i++) {
    length_output = max(length_output, dp[i]);
  }
  return length_output;
}

bool comp(string &s1, string &s2) { return s1.length() < s2.length(); }
int longestStrChain(vector<string> &arr) {
  // Write your code here.
  sort(arr.begin(), arr.end(), comp);
  return longest_string(arr);
}
int main() {
  cout << "Longest String Chain" << endl;
  vector<string> arr = {"x", "xx", "y", "xyx"};
  cout << longestStrChain(arr);

  return 0;
}