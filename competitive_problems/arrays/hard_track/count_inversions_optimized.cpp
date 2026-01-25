/******************************************************************************

Count Inversions

Given an integer array nums. Return the number of inversions in the array.



Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.



It indicates how close an array is to being sorted.


A sorted array has an inversion count of 0.


An array sorted in descending order has maximum inversion.

Example 1

Input: nums = [2, 3, 7, 1, 3, 5]

Output: 5

Explanation:

The responsible indexes are:

nums[0], nums[3], values: 2 > 1 & indexes: 0 < 3

nums[1], nums[3], values: 3 > 1 & indexes: 1 < 3

nums[2], nums[3], values: 7 > 1 & indexes: 2 < 3

nums[2], nums[4], values: 7 > 3 & indexes: 2 < 4

nums[2], nums[5], values: 7 > 5 & indexes: 2 < 5

Example 2

Input: nums = [-10, -5, 6, 11, 15, 17]

Output: 0

Explanation:

nums is sorted, hence no inversions present.
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

    /*
    // Finding the result
    // 3 4    2 4
    int left_start=0;
    int right_start=0;

    while(left_start<left.size() && right_start<right.size()){
        if(left[left_start]>right[right_start]){
            result+=((left.size()-1)-left_start)+1;
            right_start=right_start+1;
        }else{
            left_start=left_start+1;
        }
    }
    */

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

        result += (left.size() - ptr_left); // Adding count
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
  cout << "Count Inversions" << endl;
  vector<int> nums = {2, 3, 7, 1, 3, 5};
  // vector<int> nums = {-10, -5, 6, 11, 15, 17};
  Solution sol;
  cout << sol.numberOfInversions(nums);

  return 0;
}