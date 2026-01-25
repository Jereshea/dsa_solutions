/******************************************************************************

Merge two sorted arrays without extra space

Given two integer arrays nums1 and nums2. Both arrays are sorted in
non-decreasing order.



Merge both the arrays into a single array sorted in non-decreasing order.



The final sorted array should be stored inside the array nums1 and it should be
done in-place.


nums1 has a length of m + n, where the first m elements denote the elements of
nums1 and rest are 0s.


nums2 has a length of n.

Example 1

Input: nums1 = [-5, -2, 4, 5], nums2 = [-3, 1, 8]

Output: [-5, -3, -2, 1, 4, 5, 8]

Explanation:

The merged array is: [-5, -3, -2, 1, 4, 5, 8], where [-5, -2, 4, 5] are from
nums1 and [-3, 1, 8] are from nums2

Example 2

Input: nums1 = [0, 2, 7, 8], nums2 = [-7, -3, -1]

Output: [-7, -3, -1, 0, 2, 7, 8]

Explanation:

The merged array is: [-7, -3, -1, 0, 2, 7, 8], where [0, 2, 7, 8] are from nums1
and [-7, -3, -1] are from nums2
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {

    int total = m + n - 1;
    m = m - 1; // 0 based indexing
    n = n - 1;
    // Store from backwards
    while (m >= 0 && n >= 0) {
      if (nums1[m] > nums2[n]) {
        nums1[total] = nums1[m];
        m = m - 1;
        total = total - 1;
      } else {
        nums1[total] = nums2[n];
        n = n - 1;
        total = total - 1;
      }
    }

    while (m >= 0) {
      nums1[total] = nums1[m];
      m = m - 1;
      total = total - 1;
    }

    while (n >= 0) {
      nums1[total] = nums2[n];
      n = n - 1;
      total = total - 1;
    }
  }
};

int main() {
  cout << "Merge two sorted arrays without extra space" << endl;
  vector<int> nums1 = {0, 2, 7, 8, 0, 0, 0};
  vector<int> nums2 = {-7, -3, -1};
  Solution sol;
  sol.merge(nums1, 4, nums2, 3);

  for (auto &x : nums1) {
    cout << x << " ";
  }

  return 0;
}