/******************************************************************************
Print Longest Common Subsequence

Problem statement
You are given two strings ‘s1’ and ‘s2’.



Return the longest common subsequence of these strings.



If there’s no such string, return an empty string. If there are multiple
possible answers, return any such string.



Note:
Longest common subsequence of string ‘s1’ and ‘s2’ is the longest subsequence of
‘s1’ that is also a subsequence of ‘s2’. A ‘subsequence’ of ‘s1’ is a string
that can be formed by deleting one or more (possibly zero) characters from ‘s1’.


Example:
Input: ‘s1’  = “abcab”, ‘s2’ = “cbab”

Output: “bab”

Explanation:
“bab” is one valid longest subsequence present in both strings ‘s1’ , ‘s2’.

Sample Input 1:
5 6
ababa
cbbcad


Expected Answer:
"bba"

Print Longest Common Subsequence

    c b b c a d
  0 0 0 0 0 0 0
a 0 0 0 0 0 1 1
b 0 0 1 1 1 1 1
a 0 0 1 1 1 2 2
b 0 0 1 2 2 2 2
a 0 0 1 2 2 3 3
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int LCS_table(int n, int m, string &s1, string &s2, vector<vector<int>> &result,
              vector<vector<int>> &dp_array) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp_array[i][j] = 1 + dp_array[i - 1][j - 1];
      } else {
        dp_array[i][j] = max(dp_array[i - 1][j], dp_array[i][j - 1]);
      }
    }
  }
  return dp_array[n][m];
}
string findLCS(int n, int m, string &s1, string &s2) {
  // Write your code here.
  vector<vector<int>> result(n, vector<int>(m));
  vector<vector<int>> dp_array(n + 1, vector<int>(m + 1, 0));
  int result_len = LCS_table(n, m, s1, s2, result, dp_array);

  for (auto &m : dp_array) {
    for (auto &k : m) {
      cout << k << " ";
    }
    cout << endl;
  }
  // 	vector<char> output(result_len);
  string output = "";

  // Creating String from the Matrix
  int i = n; // 5
  int j = m; // 6
  int index = result_len - 1;
  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      output += s1[i - 1];
      index--;
      i--;
      j--;
    } else if (dp_array[i][j - 1] > dp_array[i - 1][j]) {
      j--;
    } else {
      i--;
    }
  }

  reverse(output.begin(), output.end());
  cout << output;

  return output;
}
int main() {
  cout << "Print Longest Common Subsequence" << endl;
  int n = 5;
  int m = 6;
  string s1 = "ababa";
  string s2 = "cbbcad";
  findLCS(n, m, s1, s2);
  return 0;
}