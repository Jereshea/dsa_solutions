/******************************************************************************
Matrix Chain Multiplication:

Given a chain of matrices A1, A2, A3,.....An. Your task is to find out the
minimum cost to multiply these matrices. The cost of matrix multiplication is
defined as the number of scalar multiplications. A Chain of matrices A1, A2,
A3,.....An is represented by a sequence of numbers in an array ‘arr’ where the
dimension of 1st matrix is equal to arr[0] * arr[1] , 2nd matrix is arr[1] *
arr[2], and so on.

For example:
For arr[ ] = { 10, 20, 30, 40}, matrix A1 = [10 * 20], A2 = [20 * 30], A3 = [30
* 40]

Scalar multiplication of matrix with dimension 10 * 20 is equal to 200.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
2
4
4 5 3 2
4
10 15 20 25
Sample Output 1:
70
8000
Sample Output Explanation 1:
In the first test case, there are three matrices of dimensions A = [4 5], B = [5
3] and C = [3 2]. The most efficient order of multiplication is A * ( B * C).
Cost of ( B * C ) = 5 * 3 * 2 = 30  and (B * C) = [5 2] and A * (B * C) = [ 4 5]
* [5 2] = 4 * 5 * 2 = 40. So the overall cost is equal to 30 + 40 =70.

In the second test case, there are two ways to multiply the chain - A1*(A2*A3)
or (A1*A2)*A3.

If we multiply in order- A1*(A2*A3), then the number of multiplications required
is 11250.

If we multiply in order- (A1*A2)*A3, then the number of multiplications required
is 8000.

Thus a minimum number of multiplications required is 8000.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
int matrixMultiplication_interval_dp(vector<int> &arr, int start, int end){

    if(start==end){
        return 0;
    }

    // Consider arr=[2,3,4]
    // Formula:
    // Consider matrix A=2*3 B=3*4

    // Operations Involved=2*3*4
    // ie) start+common_factor+end

    // Similary in the given example
    // {4, 5, 3, 2}
    // A=4*5 B=5*3  c=3*2

    //                         (AB)C  or  A(BC)
    // Matrix Output Format    4*3 3*2

    int result=INT_MAX;
    for(int i=start;i<end;i++){
        int
min_calculations=arr[start-1]*arr[i]*arr[end]+matrixMultiplication_interval_dp(arr,start,i)+matrixMultiplication_interval_dp(arr,i+1,end);
        result=min(result, min_calculations);
    }

    return result;
}
*/
int matrixMultiplication_interval_dp(vector<int> &arr, int start, int end,
                                     vector<vector<int>> &dp_array) {

  if (start == end) {
    return 0;
  }
  /*
  Consider arr=[2,3,4]
  Formula:
  Consider matrix A=2*3 B=3*4

  Operations Involved=2*3*4
  ie) start+common_factor+end

  Similary in the given example
  {4, 5, 3, 2}
  A=4*5 B=5*3  c=3*2

                          (AB)C  or  A(BC)
  Matrix Output Format    4*3 3*2
  */

  if (dp_array[start][end] != INT_MAX) {
    return dp_array[start][end];
  }
  int result = INT_MAX;
  for (int i = start; i < end; i++) {
    int min_calculations =
        arr[start - 1] * arr[i] * arr[end] +
        matrixMultiplication_interval_dp(arr, start, i, dp_array) +
        matrixMultiplication_interval_dp(arr, i + 1, end, dp_array);
    result = min(result, min_calculations);
  }

  return dp_array[start][end] = result;
}

int matrixMultiplication(vector<int> &arr, int N) {
  // Write your code here.
  /*
  Interval DP_ Step:
  1) Find all the possibilities range
  2) Find the partition range
  3) Find formula
  4) Find the base condition, to maintain exhausted range
  */
  vector<vector<int>> dp_array(N, vector<int>(N, INT_MAX));
  return matrixMultiplication_interval_dp(arr, 1, N - 1, dp_array);
}

int main() {
  cout << "Matrix Chain Multiplication" << endl;
  int n = 4;
  vector<int> arr = {4, 5, 3, 2};
  cout << matrixMultiplication(arr, n);

  return 0;
}