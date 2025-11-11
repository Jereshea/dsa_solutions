/******************************************************************************

Merge two binary Max_Heaps

Example:
n = 4; m = 3
a[] = {10, 5, 6 ,2}
b[] = {12, 7, 9}
Output: {12, 10, 9, 2, 5, 7, 6}

Algorithm:
1) Merge 2 vectors into 1
2) Heapify the new vector (bottom to up)
3) Return the result
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &result, int index, int size) {

  int largest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  if (left < size && (result[largest] < result[left])) {
    largest = left;
  }
  if (right < size && (result[largest] < result[right])) {
    largest = right;
  }
  if (largest != index) {
    swap(result[index], result[largest]);
    heapify(result, largest, size);
  }
}
void merge_max_heaps(vector<int> a, vector<int> b, int n, int m,
                     vector<int> &result) {

  for (int i = 0; i < n; i++) {
    result.push_back(a[i]);
  }

  for (int i = 0; i < m; i++) {
    result.push_back(b[i]);
  }

  int size = result.size();
  for (int i = (size / 2) - 1; i >= 0; i--) {
    heapify(result, i, size);
  }
}

int main() {
  cout << "Merge two binary Max_Heaps" << endl;
  vector<int> a = {10, 5, 6, 2};
  vector<int> b = {12, 7, 9};
  int n = 4;
  int m = 3;
  vector<int> result;
  merge_max_heaps(a, b, n, m, result);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }

  return 0;
}