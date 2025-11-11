/******************************************************************************

Minimum cost of ropes

Input:
n = 4
arr[] = {4, 3, 2, 6}

Output:29

Explanation: First connect 2 and 3 to get [4, 5, 6] with a cost of 5, then
connect 4 and 5 to get [9, 6] with a cost of 9, and finally connect 9 and 6 to
get one rope with a cost of 15, giving a total minimum cost of 29. Any other
order, such as connecting 4 and 6 first, results in a higher total cost of 38.

Algorithm:
1) Min_Heap stores the smallest element in the root (Index: 0)
2) Priority queue stores in min_heap
3) Get first smallest element (a) using top
4) Pop the element
5) Get second smallest element (b) using top
6) Add a+b
7) Parallely add it up to the cost (cost+=(a+))
8) Push a+b to the priority_queue
9) Repeat it till size of the priority queue is greater_than 1
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

long long get_cost(vector<long long> &arr, long long n) {
  long long cost = 0;
  priority_queue<long long, vector<long long>, greater<long long>> pq;

  for (long long i = 0; i < n; i++) {
    pq.push(arr[i]);
  }
  while (pq.size() > 1) {
    long long a = pq.top();
    pq.pop();
    long long b = pq.top();
    pq.pop();
    long long sum = a + b;
    pq.push(sum);
    cost += sum;
  }
  return cost;
}
int main() {
  long long n = 4;
  vector<long long> arr = {4, 3, 2, 6};
  cout << "Minimum cost of ropes: " << get_cost(arr, n) << endl;
  return 0;
}