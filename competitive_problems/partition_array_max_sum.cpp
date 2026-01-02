/******************************************************************************
Partition Array for Maximum Sum:

Problem statement
You are given an array 'arr' of 'n' integers.



You have to divide the array into some subarrays such that each element is
present in exactly one of the subarrays.



The length of each subarray should be at most 'k'. After partitioning all the
elements of each subarray will be changed to the maximum element present in that
subarray.



Find the maximum possible sum of all the elements after partitioning.



Note:

Input is given such that the answer will fit in a 32-bit integer.


Example:
Input: 'k' = 3, 'arr' = [1, 20, 13, 4, 4, 1]

Output: 80

Explanation:
We can divide the array into the following subarrays
[1,20] max of this subarray is 20 so the contribution of
this subarray in the final answer will be 20*2=40.
[13,4,4]  max of this subarray is 13 so the contribution of
this subarray in the final answer will be 13*3=39.
[1]  max of this subarray is 1 so the contribution of this
subarray in the final answer will be 1*1=1.

So, the answer will be 40 + 39 + 1 = 80.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
5 2
1 21 1 5 4


Expected Answer:
56


Output on console:
56


Explanation For Sample Output 1:
We can divide the array into the following subarrays
[1,21] max of this subarray is 21 so the contribution of this subarray in the
final answer will be 21*2=42. [1,5]  max of this subarray is 5 so the
contribution of this subarray in the final answer will be 5*2=10. [4]  max of
this subarray is 4 so the contribution of this subarray in the final answer will
be 1*4=4. So, the answer will be 42 + 10 + 4 = 56.

.

Sample Input 2 :
1 1
6


Expected Answer:
6


Output on console:
6


Expected Time Complexity:
Try to solve this in O(n*k).


Constraints:
1 <= 'n' <= 300
0 <= 'arr[i]' <= 10^9
1 <= 'k' <= 'n'

Time limit: 1 sec
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
/*
// Recursion
int maximumSubarrayPartition(vector<int> &arr, int k,int start, int end){

    if(start>=end){
        return 0;
    }
    int max_sum=INT_MIN;
    int max_element=INT_MIN;
    for(int i=start;i<min(start+k,end);i++){
        max_element=max(max_element,arr[i]);
        int
updated_element=(max_element*((i-start)+1))+maximumSubarrayPartition(arr,k,i+1,end);
        max_sum=max(max_sum,updated_element);
    }

    return max_sum;
}

int maximumSubarray(vector<int> &arr, int k){
    // Write your code here.
    return maximumSubarrayPartition(arr,k,0,arr.size());
}
*/

// Memoization
int maximumSubarrayPartition(vector<int> &arr, int k, int start, int end,
                             vector<int> &dp_array) {

  if (start >= end) {
    return 0;
  }

  if (dp_array[start] != INT_MIN) {
    return dp_array[start];
  }
  int max_sum = INT_MIN;
  int max_element = INT_MIN;
  for (int i = start; i < min(start + k, end); i++) {
    max_element = max(max_element, arr[i]);
    int updated_element =
        (max_element * ((i - start) + 1)) +
        maximumSubarrayPartition(arr, k, i + 1, end, dp_array);
    max_sum = max(max_sum, updated_element);
  }

  return dp_array[start] = max_sum;
}

int maximumSubarray(vector<int> &arr, int k) {
  // Write your code here.
  vector<int> dp_array(arr.size(), INT_MIN);
  return maximumSubarrayPartition(arr, k, 0, arr.size(), dp_array);
}

int main() {
  cout << "Partition Array Maximum Sum" << endl;
  vector<int> arr = {1, 20, 13, 4, 4, 1};
  int k = 3;
  cout << maximumSubarray(arr, k);

  return 0;
}