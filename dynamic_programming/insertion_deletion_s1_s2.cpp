/******************************************************************************
Minimum Number of Deletions and Insertions

You are given 2 non-empty strings 's1' and 's2' consisting of lowercase English
alphabets only.



In one operation you can do either of the following on 's1':

(1) Remove a character from any position in 's1'.

(2) Add a character to any position in 's1'.



Find the minimum number of operations required to convert string 's1' into 's2'.



Example:
Input: 's1' = "abcd", 's2' = "anc"

Output: 3

Explanation:
Here, 's1' = "abcd", 's2' = "anc".
In one operation remove 's1[3]', after this operation 's1' becomes "abc".
In the second operation remove 's1[1]', after this operation 's1' becomes "ac".
In the third operation add 'n' in 's1[1]', after this operation 's1' becomes
"anc".

Hence, the minimum operations required will be 3. It can be shown that there's
no way to convert s1 into s2 in less than 3 moves.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
aaa
aa


Expected Answer :
1


Output on console :
1


Explanation For Sample Output 1:
For this test case,
's1' = "aaa", 's2' = "aa"

In one operation remove 's1[2]', after this operation 's1' becomes "aa".

Hence, the output will be 1.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int find_subsequence(string &s1, string &s2, int n, int m,
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
int canYouMake(string &s1, string &s2) {
  // Write your code here.
  int n = s1.length();
  int m = s2.length();
  vector<vector<int>> dp_array(n + 1, vector<int>(m + 1, 0));
  int result = find_subsequence(s1, s2, n, m, dp_array);
  return n - result + (m - result);
}
int main() {
  cout << "Minimum Number of Deletions and Insertions" << endl;
  string s1 = "aaa";
  string s2 = "aa";
  cout << canYouMake(s1, s2);
  return 0;
}