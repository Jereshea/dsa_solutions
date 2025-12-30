/******************************************************************************
Distinct Subsequences

A Subsequence of a string is the string that is obtained by deleting 0 or more
letters from the string and keeping the rest of the letters in the same order.



We are given two strings, 'str' and 'sub'.



Find the number of subsequences of 'str' which are equal to 'sub'.



Since the answer can be very large, print it modulo 10 ^ 9 + 7.



Example :
Input: 'str' = “brootgroot” and 'sub' = “brt”

Output: 3

Explanation: The following subsequences formed by characters at given indices
(0-based) of 'str' are equal to 'sub' :

str[0] = ‘b’, str[1] = ‘r’, str[4] = ‘t’

str[0] = ‘b’, str[1] = ‘r’, str[9] = ‘t’

str[0] = ‘b’, str[6] = ‘r’, str[9] = ‘t’
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
brootgroot
brt


Sample Output 1 :
3


Explanation For Sample Input 1 :
The following subsequences formed by characters at given indices (0-based) of
'str' are equal to 'sub' :

str[0] = ‘b’, str[1] = ‘r’, str[4] = ‘t’

str[0] = ‘b’, str[1] = ‘r’, str[9] = ‘t’

str[0] = ‘b’, str[6] = ‘r’, str[9] = ‘t’
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
/*
// Recursion
int subsequence_find(string &str, string &sub,int n,int m){
    if(m<0){
        return 1;
    }
    if(n<0){
        return 0;
    }

    if(str[n]==sub[m]){
        return
(subsequence_find(str,sub,n-1,m-1)+subsequence_find(str,sub,n-1,m)); }else{
         return (subsequence_find(str,sub,n-1,m));
    }
}
int distinctSubsequences(string &str, string &sub)
{
        // Write your code here.
        return subsequence_find(str,sub,str.length()-1,sub.length()-1);
}
*/

// Memoization
int subsequence_find(string &str, string &sub, int n, int m,
                     vector<vector<int>> &dp_array) {
  if (m < 0) {
    return 1;
  }
  if (n < 0) {
    return 0;
  }

  if (dp_array[n][m] != -1) {
    return dp_array[n][m];
  }
  if (str[n] == sub[m]) {
    return dp_array[n][m] =
               (subsequence_find(str, sub, n - 1, m - 1, dp_array) +
                subsequence_find(str, sub, n - 1, m, dp_array));
  } else {
    return dp_array[n][m] = (subsequence_find(str, sub, n - 1, m, dp_array));
  }
}
int distinctSubsequences(string &str, string &sub) {
  // Write your code here.
  int n = str.length();
  int m = sub.length();
  vector<vector<int>> dp_array(n, vector<int>(m, -1));
  return subsequence_find(str, sub, str.length() - 1, sub.length() - 1,
                          dp_array);
}

int main() {
  cout << "Distinct Subsequences" << endl;
  string str = "brootgroot";
  string sub = "brt";
  cout << distinctSubsequences(str, sub);
  return 0;
}