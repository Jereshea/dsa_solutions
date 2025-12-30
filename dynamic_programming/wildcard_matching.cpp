/******************************************************************************

Wildcard Pattern Matching:

Problem statement
Given a text and a wildcard pattern of size N and M respectively, implement a
wildcard pattern matching algorithm that finds if the wildcard pattern is
matched with the text. The matching should cover the entire text not partial
text.

The wildcard pattern can include the characters ‘?’ and ‘*’

 ‘?’ – matches any single character
 ‘*’ – Matches any sequence of characters(sequence can be of length 0 or more)
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
1 <= N <= 200
1 <= M <= 200

Where 'N' denotes the length of 'TEXT' and 'M' denotes the length of 'PATTERN'.

'TEXT' and 'PATTERN' contain only lowercase letters and patterns may contain
special characters ‘*’ and ‘?’

Time Limit: 1sec
Sample Input 1:
3
?ay
ray
ab*cd
abdefcd
ab?d
abcc
Sample Output 1:
True
True
False
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
// Recursion
bool find_match(string pattern, string text, int n, int m){
    if(n<0 && m<0){
        return true;
    }

    if(m<0){
        for(int i=0;i<=n;i++){
            if(pattern[i]!='*'){
                return false;
            }
        }
        return true;
    }

    if(n<0){
        return false;
    }

    if(pattern[n]==text[m] || pattern[n]=='?'){
        return find_match(pattern, text,n-1,m-1);
    }else if(pattern[n]=='*'){
        int exclude=find_match(pattern, text,n-1,m);
        int include=find_match(pattern, text,n,m-1);

        return exclude||include;
    }else{
        return false;
    }
}
bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
   return find_match(pattern, text,pattern.length()-1,text.length()-1);
}
*/

/*
// Memoization

#include <bits/stdc++.h>

int find_match(string pattern, string text, int n, int m, vector<vector<int>>
&dp_array){ if(n<0 && m<0){ return true;
    }

    if(m<0){
        for(int i=0;i<=n;i++){
            if(pattern[i]!='*'){
                return 0;
            }
        }
        return 1;
    }

    if(n<0){
        return 0;
    }

    if(dp_array[n][m]!=-1){
        return dp_array[n][m];
    }

    if(pattern[n]==text[m] || pattern[n]=='?'){
        return dp_array[n][m]=find_match(pattern, text,n-1,m-1, dp_array);
    }else if(pattern[n]=='*'){
        int exclude=find_match(pattern, text,n-1,m,dp_array);
        int include=find_match(pattern, text,n,m-1,dp_array);

        return dp_array[n][m]=exclude||include;
    }else{
        return dp_array[n][m]=0;
    }
}
bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
   int n=pattern.length();
   int m=text.length();
   vector<vector<int>> dp_array(n+1, vector<int>(m+1,-1));
   int result= find_match(pattern, text,pattern.length()-1,text.length()-1,
dp_array); if(result==1){ return true; }else{ return false;
   }
}
*/

// Tabulation
bool find_match(string pattern, string text, int n, int m,
                vector<vector<bool>> &dp_array) {
  dp_array[0][0] = true; // pattern has 0 char; text has 0 char

  // If the pattern is no more, but the text still exist then it should return
  // false
  for (int i = 1; i <= m; i++) {
    dp_array[0][i] = false;
  }

  // If the start of the pattern is '*' and the start of the text is empty
  for (int i = 1; i <= n; i++) {
    dp_array[i][0] = dp_array[i - 1][0] && pattern[i - 1] == '*';
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?') {
        dp_array[i][j] = dp_array[i - 1][j - 1];
      } else if (pattern[i - 1] == '*') {
        int exclude = dp_array[i - 1][j];
        int include = dp_array[i][j - 1];

        dp_array[i][j] = exclude || include;
      } else {
        dp_array[i][j] = false;
      }
    }
  }

  return dp_array[n][m];
}
bool wildcardMatching(string pattern, string text) {
  // Write your code here.
  int n = pattern.length();
  int m = text.length();
  vector<vector<bool>> dp_array(n + 1, vector<bool>(m + 1, false));
  return find_match(pattern, text, pattern.length(), text.length(), dp_array);
}

int main() {
  cout << "Wildcard Pattern Matching" << endl;
  string pattern = "?ay";
  string text = "ray";
  cout << wildcardMatching(pattern, text);

  return 0;
}