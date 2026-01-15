/******************************************************************************
Union of two sorted arrays

Given two sorted arrays nums1 and nums2, return an array that contains the union
of these two arrays. The elements in the union must be in ascending order.



The union of two arrays is an array where all values are distinct and are
present in either the first array, the second array, or both.


Example 1

Input: nums1 = [1, 2, 3, 4, 5], nums2 = [1, 2, 7]

Output: [1, 2, 3, 4, 5, 7]

Explanation:

The elements 1, 2 are common to both, 3, 4, 5 are from nums1 and 7 is from nums2

Example 2

Input: nums1 = [3, 4, 6, 7, 9, 9], nums2 = [1, 5, 7, 8, 8]

Output: [1, 3, 4, 5, 6, 7, 8, 9]

Explanation:

The element 7 is common to both, 3, 4, 6, 9 are from nums1 and 1, 5, 8 is from
nums2
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> unionArray(vector<int> &nums1, vector<int> &nums2) {
    vector<int> result;
    int index1 = 0;
    int index2 = 0;

    while (index1 < nums1.size() && index2 < nums2.size()) {
      if (nums1[index1] == nums2[index2]) {
        if (result.empty() || (result[result.size() - 1] != nums1[index1])) {
          result.push_back(nums1[index1]);
        }
        index1 = index1 + 1;
        index2 = index2 + 1;
      } else if (nums1[index1] < nums2[index2]) {
        if (result.empty() || (result[result.size() - 1] != nums1[index1])) {
          result.push_back(nums1[index1]);
        }
        index1 = index1 + 1;
      } else {
        if (result.empty() || (result[result.size() - 1] != nums2[index2])) {
          result.push_back(nums2[index2]);
        }
        index2 = index2 + 1;
      }
    }

    while (index1 < nums1.size()) {
      if (result.empty() || (result[result.size() - 1] != nums1[index1])) {
        result.push_back(nums1[index1]);
      }
      index1 = index1 + 1;
    }

    while (index2 < nums2.size()) {
      if (result.empty() || (result[result.size() - 1] != nums2[index2])) {
        result.push_back(nums2[index2]);
      }
      index2 = index2 + 1;
    }
    return result;
  }
};

int main() {
  cout << "Union of two sorted arrays" << endl;
  vector<int> nums1 = {3, 4, 6, 7, 9, 9};
  vector<int> nums2 = {1, 5, 7, 8, 8};

  Solution sol;
  vector<int> result = sol.unionArray(nums1, nums2);

  for (auto &m : result) {
    cout << m << " ";
  }

  return 0;
}