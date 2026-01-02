/******************************************************************************
Palindrome Partitioning II:
You are given a string 'str' of length 'n'.



Find the minimum number of partitions in the string so that no partition is
empty and every partitioned substring is a palindrome.



Example :
Input: 'str' = "aaccb"

Output: 2

Explanation: We can make a valid partition like aa | cc | b.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
aaccb


Sample Output 1 :
2


Explanation of sample input 1 :
We can make a valid partition like aa | cc | b.


Sample Input 2 :
ababa


Sample Output 2 :
0


Explanation of sample input 2 :
The string is already a palindrome, so we need not make any partition.


Sample Input 3:
aababa


Sample Output 3:
1


Expected time complexity :
You can submit a solution of time complexity O(n ^ 3) but also try to write the
solution having complexity O(n ^ 2).


Constraints :
1 <= 'n' <= 100

Time limit: 1 second
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
// Recusrion
bool isPalindrome(int start, int end, string &str){
    // aba
    if(start==end){
        return true;
    }
    while(start<end){
        if(str[start]!=str[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
int partition_palindrome(string &str, int start, int end){
    if(start>end){
        return 0;
    }
    int min_cost=INT_MAX;
    int cost=0;
    for(int i=start;i<=end;i++){
        if(isPalindrome(start,i,str)){
            if(i==end){
                cost=0;
            }else{
                cost=1+partition_palindrome(str,i+1,end);
            }
            min_cost=min(min_cost,cost);
        }
    }

    return min_cost;
}
int palindromePartitioning(string str)
{
    // Write your code here
    return partition_palindrome(str, 0,str.length()-1);
}
*/

// Memoization
bool isPalindrome(int start, int end, string &str) {
  // aba
  if (start == end) {
    return true;
  }
  while (start < end) {
    if (str[start] != str[end]) {
      return false;
    }
    start++;
    end--;
  }
  return true;
}
int partition_palindrome(string &str, int start, int end,
                         vector<int> dp_array) {
  if (start > end) {
    return 0;
  }

  if (dp_array[start] != INT_MAX) {
    return dp_array[start];
  }
  int min_cost = INT_MAX;
  int cost = 0;
  for (int i = start; i <= end; i++) {
    if (isPalindrome(start, i, str)) {
      if (i == end) {
        cost = 0;
      } else {
        cost = 1 + partition_palindrome(str, i + 1, end, dp_array);
      }
      min_cost = min(min_cost, cost);
    }
  }

  return dp_array[start] = min_cost;
}
int palindromePartitioning(string str) {
  // Write your code here
  vector<int> dp_array(str.length(), INT_MAX);
  return partition_palindrome(str, 0, str.length() - 1, dp_array);
}

int main() {
  cout << "Palindrome Partitioning II" << endl;
  string str = "aaccb";
  cout << palindromePartitioning(str);

  return 0;
}