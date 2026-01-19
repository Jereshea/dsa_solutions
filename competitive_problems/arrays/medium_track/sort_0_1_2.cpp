/******************************************************************************

Sort an array of 0's 1's and 2's

Given an array nums consisting of only 0, 1, or 2. Sort the array in
non-decreasing order.



The sorting must be done in-place, without making a copy of the original array.


Example 1

Input: nums = [1, 0, 2, 1, 0]

Output: [0, 0, 1, 1, 2]

Explanation:

The nums array in sorted order has 2 zeroes, 2 ones and 1 two

Example 2

Input: nums = [0, 0, 1, 1, 1]

Output: [0, 0, 1, 1, 1]

Explanation:

The nums array in sorted order has 2 zeroes, 3 ones and zero twos
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void sortZeroOneTwo(vector<int> &nums) {
    int zero_index = 0;
    int one_index = 0;
    int two_index = nums.size() - 1;

    while (one_index <= two_index) {
      if (nums[one_index] == 0) {
        int temp = nums[zero_index];
        nums[zero_index] = 0;
        nums[one_index] = temp;
        zero_index = zero_index + 1;
        one_index = one_index + 1;
      }

      else if (nums[one_index] == 1) {
        one_index = one_index + 1;
      }

      else {
        int temp = nums[two_index];
        nums[two_index] = 2;
        nums[one_index] = temp;
        two_index = two_index - 1;
      }
    }
  }
};

int main() {
  cout << "Sort an array of 0's 1's and 2's" << endl;
  vector<int> nums = {1, 0, 2, 1, 0};
  // vector<int> nums = {2, 0, 1};
  Solution sol;
  sol.sortZeroOneTwo(nums);
  for (auto &m : nums) {
    cout << m << " ";
  }
  return 0;
}