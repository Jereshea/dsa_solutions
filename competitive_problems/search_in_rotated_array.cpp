/*******************
Search In Rotated Sorted Array

Problem statement
Aahad and Harshit always have fun by solving problems. Harshit took a sorted
array consisting of distinct integers and rotated it clockwise by an unknown
amount. For example, he took a sorted array = [1, 2, 3, 4, 5] and if he rotates
it by 2, then the array becomes: [4, 5, 1, 2, 3].

After rotating a sorted array, Aahad needs to answer Q queries asked by Harshit,
each of them is described by one integer Q[i]. which Harshit wanted him to
search in the array. For each query, if he found it, he had to shout the index
of the number, otherwise, he had to shout -1.

For each query, you have to complete the given method where 'key' denotes Q[i].
If the key exists in the array, return the index of the 'key', otherwise, return
-1.

Note:

Can you solve each query in O(logN) ?
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 10^6
-10^9 <= A[i] <= 10^9
1 <= Q <= 10^5
-10^9 <= Q[i] <= 10^9

Time Limit: 1sec
Sample Input 1:
4
2 5 -3 0
2
5
1
Sample Output 1:
1
-1
Explanation For Sample Input 1:
In the 1st test case, 5 is found at index 1

In the 2nd test case, 1 is not found in the array, hence return -1.
Sample Input 2:
5
100 -2 6 10 11
2
100
6
Sample Output 2:
0
2
********************* */

#include <bits/stdc++.h>
using namespace std;

int binary_search(int *arr, int start, int end, int key) {
  // -3 0 2 5
  //  0 1 2 3
  if (start > end || end < 0) {
    return -1;
  }

  int mid = start + ((end - start) / 2);
  if (arr[mid] == key) {
    return mid;
  } else if (arr[mid] > key) {
    return binary_search(arr, start, mid - 1, key);
  } else {
    return binary_search(arr, mid + 1, end, key);
  }
}
int search(int *arr, int n, int key) {
  int pivot = 0;

  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1]) {
      pivot = i;
      break;
    }
  }
  if (pivot == 0) {
    return binary_search(arr, 0, n - 1, key);
  }
  // Find which position has the element
  else if (arr[0] <= key && arr[pivot - 1] >= key) {
    return binary_search(arr, 0, pivot - 1, key);
  } else {
    return binary_search(arr, pivot, n - 1, key);
  }
}

int main() {
  cout << "Search In Rotated Sorted Array" << endl;
  int n = 5;
  int arr[n] = {4, -1, 0, 2, 3};
  int key = 4;
  cout << search(arr, n, key);
  return 0;
}