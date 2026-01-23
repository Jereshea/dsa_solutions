/******************************************************************************

Next Permutation:

A permutation of an array of integers is an arrangement of its members into a
sequence or linear order.



For example, for arr = [1,2,3], the following are all the permutations of arr:

[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1].



The next permutation of an array of integers is the next lexicographically
greater permutation of its integers.

More formally, if all the permutations of the array are sorted in
lexicographical order, then the next permutation of that array is the
permutation that follows it in the sorted order.



If such arrangement is not possible (i.e., the array is the last permutation),
then rearrange it to the lowest possible order (i.e., sorted in ascending
order).



You must rearrange the numbers in-place and use only constant extra memory.


Example 1

Input: nums = [1,2,3]

Output: [1,3,2]

Explanation:

The next permutation of [1,2,3] is [1,3,2].

Example 2

Input: nums = [3,2,1]

Output: [1,2,3]

Explanation:

[3,2,1] is the last permutation. So we return the first: [1,2,3].

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // void nextPermutation(vector<int>& nums) {
  //     // Your code goes here
  //     next_permutation(nums.begin(),nums.end());
  // }
  void nextPermutation(vector<int> &nums) {
    // Your code goes here
    // it will be stored in the lexicographical order, so find the index where i
    // < i+1 Consider    1 2 4 3 (find index where index > index+1) ; store
    // index and index-1 here the next permutation will be 1 3 2 4
    // sort() -> O(n log n)
    // reverse() -> O(n)
    int t1 = -1;
    int t2 = 0;
    for (int i = nums.size() - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
        t1 = i;
        t2 = i + 1;
        break;
      }
    }

    if (t1 == -1) {
      // sort(nums.begin(),nums.end());
      reverse(nums.begin(), nums.end());
    } else {
      // find the element larger than t1, but the smallest among all the largest
      int min_largest = INT_MAX;
      int min_largest_index;
      for (int i = t2; i < nums.size(); i++) {
        if (nums[t1] < nums[i]) {
          if (min_largest != min(min_largest, nums[i])) {
            min_largest = min(min_largest, nums[i]);
            min_largest_index = i;
          }
        }
      }
      swap(nums[t1], nums[min_largest_index]);
      // then rearrange the remaining parts in the ascending order
      // sort(nums.begin()+t2, nums.end());
      reverse(nums.begin() + t2, nums.end());
    }
  }
};

int main() {
  cout << "Next Permutation" << endl;
  // vector<int> nums = {3,2,1};
  vector<int> nums = {1, 2, 3};
  Solution sol;
  sol.nextPermutation(nums);
  for (auto &m : nums) {
    cout << m << " ";
  }
  return 0;
}