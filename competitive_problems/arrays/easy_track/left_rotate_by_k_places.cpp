/******************************************************************************

Left Rotate Array by K Places

Given an integer array nums and a non-negative integer k, rotate the array to
the left by k steps.


Example 1

Input: nums = [1, 2, 3, 4, 5, 6], k = 2

Output: nums = [3, 4, 5, 6, 1, 2]

Explanation:

rotate 1 step to the left: [2, 3, 4, 5, 6, 1]

rotate 2 steps to the left: [3, 4, 5, 6, 1, 2]

Example 2

Input: nums = [3, 4, 1, 5, 3, -5]

Output: nums = [1, 5, 3, -5, 3, 4]

Explanation:

rotate 1 step to the left: [4, 1, 5, 3, -5, 3]

rotate 2 steps to the left: [1, 5, 3, -5, 3, 4]

rotate 3 steps to the left: [5, 3, -5, 3, 4, 1]

rotate 4 steps to the left: [3, -5, 3, 4, 1, 5]

rotate 5 steps to the left: [-5, 3, 4, 1, 5, 3]

rotate 6 steps to the left: [3, 4, 1, 5, 3, -5]

rotate 7 steps to the left: [4, 1, 5, 3, -5, 3]

rotate 8 steps to the left: [1, 5, 3, -5, 3, 4]
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void rotateArray(vector<int> &nums, int k) {
    int index = 0;
    vector<int> temp;
    k = k % nums.size();
    for (int i = k; i < nums.size(); i++) {
      if (index < k) {
        temp.push_back(nums[index]);
      }
      nums[index] = nums[i];
      index = index + 1;
    }

    for (int i = 0; i < temp.size(); i++) {
      nums[index] = temp[i];
    }
  }
};

int main() {
  cout << "Left Rotate Array by K Places" << endl;
  vector<int> nums = {3, 4, 1, 5, 3, -5};
  int k = 8;
  for (auto &m : nums) {
    cout << m << " ";
  }
  cout << endl;
  Solution sol;
  sol.rotateArray(nums, k);
  for (auto &m : nums) {
    cout << m << " ";
  }

  return 0;
}