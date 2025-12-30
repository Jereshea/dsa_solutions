/******************************************************************************
Minimum insertions to make a string palindrome

A palindrome string is one that reads the same backward as well as forward.



You are given a string 'str'.



Find the minimum number of characters needed to insert in 'str' to make it a
palindromic string.



Example :
Input: 'str' = "abca"

Output: 1

Explanation:
If we insert the character ‘b’ after ‘c’, we get the string "abcba", which is a
palindromic string. Please note that there are also other ways possible.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
abca


Sample Output 1:
1


Explanation for input 1:
If we insert the character ‘b’ after ‘c’, we get the string "abcba", which is a
palindromic string. Please note that there are also other ways possible.
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
int minimumInsertions(string &s) {
  // Write your code here.
  string s_reverse = s;
  reverse(s_reverse.begin(), s_reverse.end());
  int n = s.length();
  vector<vector<int>> dp_array(n + 1, vector<int>(n + 1, 0));
  return n - find_subsequence(s, s_reverse, n, n, dp_array);
}
int main() {
  cout << "Minimum insertions to make a string palindrome" << endl;
  string s = "abca";
  cout << minimumInsertions(s);
  return 0;
}