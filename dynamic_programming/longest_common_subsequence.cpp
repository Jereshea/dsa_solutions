/******************************************************************************

Longest Common Subsequence:

Given two strings, 'S' and 'T' with lengths 'M' and 'N', find the length of the
'Longest Common Subsequence'.

For a string 'str'(per se) of length K, the subsequences are the strings
containing characters in the same relative order as they are present in 'str,'
but not necessarily contiguous. Subsequences contain all the strings of length
varying from 0 to K.

Example :
Subsequences of string "abc" are:  ""(empty string), a, b, c, ab, bc, ac, abc.

adebc
dcadb
Sample Output 1 :
3
Explanation of the Sample Output 1 :
Both the strings contain a common subsequence 'adb', which is the longest common
subsequence with length 3.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
// Recursion
int lcs_find(string s, string t, int index_s, int index_t){
    if(index_s<0 || index_t<0){
        return 0;
    }

    if(s[index_s]==t[index_t]){
        return 1+lcs_find(s,t,index_s-1, index_t-1);
    }
    return max(lcs_find(s,t,index_s-1, index_t),lcs_find(s,t,index_s,
index_t-1));
}
int lcs(string s, string t)
{
        //Write your code here
        int index_s=s.length()-1;
        int index_t=t.length()-1;
        return lcs_find(s,t,index_s,index_t);
}
*/

/*
// Memoization
int lcs_find(string s, string t, int index_s, int index_t, vector<vector<int>>
&dp_array){ if(index_s<0 || index_t<0){ return 0;
    }

    if(dp_array[index_s][index_t]!=-1){
        return dp_array[index_s][index_t];
    }
    if(s[index_s]==t[index_t]){
        return dp_array[index_s][index_t]=1+lcs_find(s,t,index_s-1, index_t-1,
dp_array);
    }
    return dp_array[index_s][index_t]=max(lcs_find(s,t,index_s-1,
index_t,dp_array),lcs_find(s,t,index_s, index_t-1,dp_array));
}
int lcs(string s, string t)
{
        //Write your code here
        int index_s=s.length()-1;
        int index_t=t.length()-1;
        vector<vector<int>> dp_array(index_s+1, vector<int>(index_t+1,-1));
        return lcs_find(s,t,index_s,index_t, dp_array);
}
*/

// Tabulation
int lcs_find(string s, string t, int index_s, int index_t,
             vector<vector<int>> &dp_array) {

  for (int i = 1; i <= index_s; i++) {
    for (int j = 1; j <= index_t; j++) {
      if (s[i - 1] == t[j - 1]) {
        dp_array[i][j] = 1 + dp_array[i - 1][j - 1];
      } else {
        dp_array[i][j] = max(dp_array[i - 1][j], dp_array[i][j - 1]);
      }
    }
  }

  return dp_array[index_s][index_t];
}
int lcs(string s, string t) {
  // Write your code here
  int index_s = s.length();
  int index_t = t.length();
  vector<vector<int>> dp_array(index_s + 1, vector<int>(index_t + 1, 0));
  return lcs_find(s, t, index_s, index_t, dp_array);
}
int main() {
  cout << "Longest Common Subsequence" << endl;
  string s = "adebc";
  string t = "dcadb";
  // cout<<s.length();
  // cout<<t.length();
  cout << lcs(s, t);

  return 0;
}