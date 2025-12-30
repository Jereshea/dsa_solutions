/******************************************************************************
Longest Common Substring:

You are given two strings, 'str1' and 'str2'. You have to find the length of the
longest common substring.



A substring is a continuous segment of a string. For example, "bcd" is a
substring of "abcd", while "acd" or "cda" are not.



Example:
Input: ‘str1’ = “abcjklp” , ‘str2’ = “acjkp”.

Output: 3

Explanation:  The longest common substring between ‘str1’ and ‘str2’ is “cjk”,
of length 3. Detailed explanation ( Input/output format, Notes, Images ) Sample
Input 1: wasdijkl wsdjkl Sample Output 1:
 3
Explanation Of Sample Input 1 :
 The longest common substring is “jkl”, of length 3.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int substring_table(string &str1, string &str2, int n, int m,
                    vector<vector<int>> &dp_array, int &result) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (str1[i - 1] == str2[j - 1]) {
        dp_array[i][j] = 1 + dp_array[i - 1][j - 1];
        result = max(result, dp_array[i][j]);
      }
    }
  }

  return dp_array[n][m];
}
int lcs(string &str1, string &str2) {
  // Write your code here.
  int n = str1.length();
  int m = str2.length();
  vector<vector<int>> dp_array(n + 1, vector<int>(m + 1, 0));

  int result = INT_MIN;
  substring_table(str1, str2, n, m, dp_array, result);

  return result;
}

int main() {
  cout << "Longest Common Substring" << endl;
  string str1 = "wasdijkl";
  string str2 = "wsdjkl";
  cout << lcs(str1, str2);

  return 0;
}