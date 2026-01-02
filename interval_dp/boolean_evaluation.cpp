/******************************************************************************
Boolean Evaluation:

You are given an expression 'exp' in the form of a string where operands will be
: (TRUE or FALSE), and operators will be : (AND, OR or XOR).



Now you have to find the number of ways we can parenthesize the expression such
that it will evaluate to TRUE.



As the answer can be very large, return the output modulo 1000000007.



Note :

‘T’ will represent the operand TRUE.
‘F’ will represent the operand FALSE.
‘|’ will represent the operator OR.
‘&’ will represent the operator AND.
‘^’ will represent the operator XOR.
Example :

Input: 'exp’ = "T|T & F".

Output: 1

Explanation:
There are total 2  ways to parenthesize this expression:
    (i) (T | T) & (F) = F
    (ii) (T) | (T & F) = T
Out of 2 ways, one will result in True, so we will return 1.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
T^T^F
Sample Output 1 :
0
Explanation For Sample Input 1:
There are total 2  ways to parenthesize this expression:
(i) (T^T)^(F) = F
(ii) (T)^(T^F) = F
Both ways will result in False, so we will return 0.
Sample Input 2 :
F|T^F
Sample Output 2 :
2
Explanation For Sample Input 2:
For the first test case:
There are total 2  ways to parenthesize this expression:
(i) (F|T)^(F) = T
(ii) (F)|(T^F) = T
Both ways will result in True, so we will return 2.
Expected time complexity
The expected time complexity is O(n ^ 3), where 'n' denotes the length of 'exp'.
Constraints:
3 <= |‘exp’| <= 200
Where |'exp'| denotes the length of 'exp'.

Time Limit: 1 sec
*******************************************************************************/

#include <bits/stdc++.h>
#define MODO 1000000007
using namespace std;

/*
// Recursion
int evaluateExp_intervalDP(string &expr, int start, int end,bool isTrue){
    if(start>end){
        return 0;
    }

    if(start==end){
        if (isTrue){
            return expr[start]=='T';
        }else{
            return expr[start]=='F';
        }
    }

    int countWays=0;
    for(int i=start+1;i<=end-1;i=i+2){
        int leftTrue=evaluateExp_intervalDP(expr,start,i-1,1);
        int leftFalse=evaluateExp_intervalDP(expr,start,i-1,0);
        int rightTrue=evaluateExp_intervalDP(expr,i+1,end,1);
        int rightFalse=evaluateExp_intervalDP(expr,i+1,end,0);

        if(expr[i]=='&'){
            // only is both left and right becomes true it is valid
            if(isTrue){
                countWays+=leftTrue*rightTrue;
            }else{
                countWays+=(leftFalse*rightFalse) + (leftFalse*rightTrue) +
(leftTrue*rightFalse);
            }
        }else if(expr[i]=='|'){
            // either left or right is sufficient. Else both left and right can
be true if(isTrue){ countWays+=(leftTrue*rightTrue)+(leftFalse*rightTrue) +
(leftTrue*rightFalse); }else{ countWays+=(leftFalse*rightFalse);
            }
        }else{
            if(isTrue){
                // if only one part of the either side is true, gives true
                countWays+=(leftTrue*rightFalse)+(leftFalse*rightTrue);
            }else{
                countWays+=(leftTrue*rightTrue)+(leftFalse*rightFalse);
            }
        }
    }
    return countWays;
}
int evaluateExp(string & expr) {
    // Write your code here.
    return evaluateExp_intervalDP(expr,0,expr.size()-1,1);
}
*/

// Memoization
int evaluateExp_intervalDP(string &expr, int start, int end, bool isTrue,
                           vector<vector<vector<int>>> &dp_array) {
  if (start > end) {
    return 0;
  }

  if (dp_array[start][end][isTrue] != -1) {
    return dp_array[start][end][isTrue];
  }

  if (start == end) {
    if (isTrue) {
      return expr[start] == 'T';
    } else {
      return expr[start] == 'F';
    }
  }

  long long countWays = 0;
  for (int i = start + 1; i <= end - 1; i = i + 2) {
    long long leftTrue =
        evaluateExp_intervalDP(expr, start, i - 1, 1, dp_array);
    long long leftFalse =
        evaluateExp_intervalDP(expr, start, i - 1, 0, dp_array);
    long long rightTrue = evaluateExp_intervalDP(expr, i + 1, end, 1, dp_array);
    long long rightFalse =
        evaluateExp_intervalDP(expr, i + 1, end, 0, dp_array);

    if (expr[i] == '&') {
      // only is both left and right becomes true it is valid
      if (isTrue) {
        countWays = (countWays + (leftTrue * rightTrue) % MODO) % MODO;
      } else {
        countWays = (countWays + (((leftFalse * rightFalse) % MODO) +
                                  ((leftFalse * rightTrue) % MODO) +
                                  ((leftTrue * rightFalse) % MODO))) %
                    MODO;
      }
    } else if (expr[i] == '|') {
      // either left or right is sufficient. Else both left and right can be
      // true
      if (isTrue) {
        countWays = (countWays + ((leftTrue * rightTrue) % MODO) +
                     ((leftFalse * rightTrue) % MODO) +
                     ((leftTrue * rightFalse) % MODO)) %
                    MODO;
      } else {
        countWays = (countWays + (leftFalse * rightFalse) % MODO) % MODO;
      }
    } else {
      if (isTrue) {
        // if only one part of the either side is true, gives true
        countWays = (countWays + ((leftTrue * rightFalse) % MODO) +
                     ((leftFalse * rightTrue) % MODO)) %
                    MODO;
      } else {
        countWays = (countWays + ((leftTrue * rightTrue) % MODO) +
                     ((leftFalse * rightFalse) % MODO)) %
                    MODO;
      }
    }
  }
  return dp_array[start][end][isTrue] = (int)countWays % MODO;
}
int evaluateExp(string &expr) {
  // Write your code here.
  vector<vector<vector<int>>> dp_array(
      expr.size() + 1,
      vector<vector<int>>(expr.size() + 1, vector<int>(2, -1)));
  return evaluateExp_intervalDP(expr, 0, expr.size() - 1, 1, dp_array);
}

int main() {
  cout << "Boolean Evaluation" << endl;
  string expr = "F|T^F";
  cout << evaluateExp(expr);

  return 0;
}