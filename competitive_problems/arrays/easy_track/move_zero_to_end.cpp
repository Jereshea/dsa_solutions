/******************************************************************************

Move Zeros to End

Given an integer array nums, move all the 0's to the end of the array. The
relative order of the other elements must remain the same.



This must be done in place, without making a copy of the array.


Example 1

Input: nums = [0, 1, 4, 0, 5, 2]

Output: [1, 4, 5, 2, 0, 0]

Explanation:

Both the zeroes are moved to the end and the order of the other elements stay
the same

Example 2

Input: nums = [0, 0, 0, 1, 3, -2]

Output: [1, 3, -2, 0, 0, 0]

Explanation:

All 3 zeroes are moved to the end and the order of the other elements stay the
same

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int index = 0;
    int count_zeroes = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        count_zeroes = count_zeroes + 1;
      } else {
        nums[index] = nums[i];
        index = index + 1;
      }
    }
    for (int i = 0; i < count_zeroes; i++) {
      nums[index] = 0;
      index = index + 1;
    }
  }
};

int main() {
  cout << "Move Zeros to End" << endl;
  vector<int> nums = {0, 1, 4, 0, 5, 2};
  for (auto &m : nums) {
    cout << m << " ";
  }
  cout << endl;
  Solution sol;
  sol.moveZeroes(nums);
  for (auto &m : nums) {
    cout << m << " ";
  }

  return 0;
}