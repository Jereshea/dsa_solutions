/******************************************************************************

Reverse Pairs

Given an integer array nums. Return the number of reverse pairs in the array.



An index pair (i, j) is called a reverse pair if:



0 <= i < j < nums.length


nums[i] > 2 * nums[j]

Example 1

Input: nums = [6, 4, 1, 2, 7]

Output: 3

Explanation:

The reverse pairs are:

(0, 2) : nums[0] = 6, nums[2] = 1, 6 > 2 * 1

(0, 3) : nums[0] = 6, nums[3] = 2, 6 > 2 * 2

(1, 2) : nums[1] = 4, nums[2] = 1, 4 > 2 * 1

Example 2

Input: nums = [5, 4, 4, 3, 3]

Output: 0

Explanation:

No pairs satisfy both the conditons.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void merging(vector<int> &nums, long long int &result, int start, int mid,
               int end) {
    vector<int> left;
    vector<int> right;

    for (int i = start; i <= mid; i++) {
      left.push_back(nums[i]);
    }

    for (int i = mid + 1; i <= end; i++) {
      right.push_back(nums[i]);
    }

    // Finding the result
    // 3 4    2 4
    int left_start = 0;
    int right_start = 0;

    while (left_start < left.size() && right_start < right.size()) {
      if (left[left_start] > 2LL * right[right_start]) {
        result += ((left.size() - 1) - left_start) + 1;
        right_start = right_start + 1;
      } else {
        left_start = left_start + 1;
      }
    }

    // Merging
    int ptr_left = 0;
    int ptr_right = 0;
    while (ptr_left < left.size() && ptr_right < right.size()) {
      if (left[ptr_left] <= right[ptr_right]) {
        nums[start] = left[ptr_left];
        start = start + 1;
        ptr_left = ptr_left + 1;
      } else {
        nums[start] = right[ptr_right];
        start = start + 1;
        ptr_right = ptr_right + 1;

        // result+=(left.size()-ptr_left); // Adding count
      }
    }

    while (ptr_left < left.size()) {
      nums[start] = left[ptr_left];
      start = start + 1;
      ptr_left = ptr_left + 1;
    }

    while (ptr_right < right.size()) {
      nums[start] = right[ptr_right];
      start = start + 1;
      ptr_right = ptr_right + 1;
    }
  }
  void inversions_merge_sort(vector<int> &nums, long long int &result,
                             int start, int end) {

    if (start >= end) {
      return;
    }
    int mid = start + ((end - start) / 2);
    inversions_merge_sort(nums, result, start, mid);
    inversions_merge_sort(nums, result, mid + 1, end);
    merging(nums, result, start, mid, end);
  }
  long long int numberOfInversions(vector<int> nums) {
    long long int result = 0;
    inversions_merge_sort(nums, result, 0, nums.size() - 1);
    return result;
  }
};

int main() {
  cout << "Reverse Pairs" << endl;
  vector<int> nums = {6, 4, 1, 2, 7};
  // vector<int> nums = {5, 4, 4, 3, 3};
  Solution sol;
  cout << sol.numberOfInversions(nums);

  return 0;
}