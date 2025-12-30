/******************************************************************************
Longest Palindromic Subsequence:

You have been given a string ‘A’ consisting of lower case English letters. Your
task is to find the length of the longest palindromic subsequence in ‘A’.

A subsequence is a sequence generated from a string after deleting some or no
characters of the string without changing the order of the remaining string
characters. (i.e. “ace” is a subsequence of “abcde” while “aec” is not).

A string is said to be palindrome if the reverse of the string is the same as
the actual string. For example, “abba” is a palindrome, but “abbc” is not a
palindrome.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int find_subsequence(string &s, string &s_reverse, int n, int m,
                     vector<vector<int>> &dp_array) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i - 1] == s_reverse[j - 1]) {
        dp_array[i][j] = 1 + dp_array[i - 1][j - 1];
      } else {
        dp_array[i][j] = max(dp_array[i - 1][j], dp_array[i][j - 1]);
      }
    }
  }

  return dp_array[n][m];
}
int longestPalindromeSubsequence(string &s) {
  // Write your code here.
  string s_reverse = s;
  reverse(s_reverse.begin(), s_reverse.end());
  int n = s.length();
  vector<vector<int>> dp_array(n + 1, vector<int>(n + 1, 0));
  return find_subsequence(s, s_reverse, n, n, dp_array);
}
int main() {
  cout << "Longest Palindromic Subsequence" << endl;
  string s = "bbabcbcab";
  cout << longestPalindromeSubsequence(s);
  return 0;
}