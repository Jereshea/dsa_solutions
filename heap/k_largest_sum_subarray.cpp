/******************************************************************************

Kth Largest Sum SUbarray
Given an array arr[] of size n, the task is to find the kth largest sum of
contiguous subarray within the array of numbers that has both negative and
positive numbers.

Examples:

Input: arr[] = [20, -5, -1], k = 3
Output: 14
Explanation: All sum of contiguous subarrays are (20, 15, 14, -5, -6, -1), so
the 3rd largest sum is 14.

Algorithm:
1) Store the first k sum of subarrays in a Min Heap
2) For the remaining sum of subarrays push it to the heap, only if the top node
is smaller than the sum 3) Thus in the heap we get the k largest elements 4) But
as we are storing it in the Min_heap, the top will be the kth largest element
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int k_largest_sum_subarray(vector<int> &input, int k) {
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < input.size(); i++) {
    int sum = 0;
    for (int j = i; j < input.size(); j++) {
      sum += input[j];
      if (pq.size() < k) {
        pq.push(sum);
      } else {
        if (pq.top() < sum) {
          pq.pop();
          pq.push(sum);
        }
      }
    }
  }
  return pq.top();
}
int main() {
  cout << "Kth Largest Sum Subarray: ";
  vector<int> input = {20, -5, -1};
  int k = 3;
  cout << k_largest_sum_subarray(input, k);

  return 0;
}