/******************************************************************************

Left Rotate Array by One

Given an integer array nums, rotate the array to the left by one.



Note: There is no need to return anything, just modify the given array.


Example 1

Input: nums = [1, 2, 3, 4, 5]

Output: [2, 3, 4, 5, 1]

Explanation:

Initially, nums = [1, 2, 3, 4, 5]

Rotating once to left -> nums = [2, 3, 4, 5, 1]

Example 2

Input: nums = [-1, 0, 3, 6]

Output: [0, 3, 6, -1]

Explanation:

Initially, nums = [-1, 0, 3, 6]

Rotating once to left -> nums = [0, 3, 6, -1]
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void rotateArrayByOne(vector<int> &nums) {
    int num1 = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      nums[i - 1] = nums[i];
    }
    nums[nums.size() - 1] = num1;
  }
};

int main() {
  cout << "Left Rotate Array by One" << endl;
  vector<int> nums = {-1, 0, 3, 6};
  for (auto &m : nums) {
    cout << m << " ";
  }
  cout << endl;
  Solution sol;
  sol.rotateArrayByOne(nums);
  for (auto &m : nums) {
    cout << m << " ";
  }

  return 0;
}