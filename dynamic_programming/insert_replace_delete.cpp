/******************************************************************************
Edit Distance:

You are given two strings 'S' and 'T' of lengths 'N' and 'M' respectively. Find
the "Edit Distance" between the strings.

Edit Distance of two strings is the minimum number of steps required to make one
string equal to the other. In order to do so, you can perform the following
three operations:

1. Delete a character
2. Replace a character with another one
3. Insert a character
Note:
Strings don't contain spaces in between.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
0 <= N <= 10 ^ 3
0 <= M <= 10 ^ 3

Time Limit : 1sec
Sample Input 1 :
abc
dc
Sample Output 1 :
2
 Explanation For Sample Input 1 :
In 2 operations we can make the string T to look like string S. First, insert
the character 'a' to string T, which makes it "adc".

And secondly, replace the character 'd' of the string T with 'b' from the string
S. This would make string T to "abc" which is also the string S. Hence, the
minimum distance.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
// Recursion
int find_ops(string str1, string str2, int n, int m){

    if(n<0){
        return m+1;
    }

    if(m<0){
        return n+1;
    }
    if(str1[n]==str2[m]){
        return 0+find_ops(str1,str2, n-1,m-1);
    }

    int insert=1+find_ops(str1,str2, n,m-1);
    int replace=1+find_ops(str1,str2, n-1,m-1);
    int deletion=1+find_ops(str1,str2, n-1,m);

    return min(insert,min(deletion,replace));
}
int editDistance(string str1, string str2)
{
    //write you code here
    return find_ops(str1,str2, str1.length()-1,str2.length()-1);
}
*/

/*
// Memoization
int find_ops(string str1, string str2, int n, int m, vector<vector<int>>
&dp_array){

    if(n<0){
        return m+1;
    }

    if(m<0){
        return n+1;
    }

    if(dp_array[n][m]!=-1){
        return dp_array[n][m];
    }
    if(str1[n]==str2[m]){
        return dp_array[n][m]=0+find_ops(str1,str2, n-1,m-1,dp_array);
    }

    int insert=1+find_ops(str1,str2, n,m-1,dp_array);
    int replace=1+find_ops(str1,str2, n-1,m-1,dp_array);
    int deletion=1+find_ops(str1,str2, n-1,m,dp_array);

    return dp_array[n][m]=min(insert,min(deletion,replace));
}
int editDistance(string str1, string str2)
{
    //write you code here
    vector<vector<int>>
dp_array(str1.length()+1,vector<int>(str2.length()+1,-1)); return
find_ops(str1,str2, str1.length()-1,str2.length()-1,dp_array);
}
*/

// Tabulation
int find_ops(string str1, string str2, int n, int m,
             vector<vector<int>> &dp_array) {

  for (int i = 0; i <= n; i++) {
    dp_array[i][0] = i;
  }
  for (int j = 0; j <= m; j++) {
    dp_array[0][j] = j;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (str1[i - 1] == str2[j - 1]) {
        dp_array[i][j] = dp_array[i - 1][j - 1];
      } else {
        int insert = 1 + dp_array[i][j - 1];
        int replace = 1 + dp_array[i - 1][j - 1];
        int deletion = 1 + dp_array[i - 1][j];
        dp_array[i][j] = min(insert, min(replace, deletion));
      }
    }
  }

  return dp_array[n][m];
}
int editDistance(string str1, string str2) {
  // write you code here
  vector<vector<int>> dp_array(str1.length() + 1,
                               vector<int>(str2.length() + 1, -1));
  return find_ops(str1, str2, str1.length(), str2.length(), dp_array);
}
int main() {
  cout << "Edit Distance" << endl;
  string str1 = "abc";
  string str2 = "dc";
  cout << editDistance(str1, str2);

  return 0;
}