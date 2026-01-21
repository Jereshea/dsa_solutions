/******************************************************************************

Rearrange array elements by sign:

Given an integer array nums of even length consisting of an equal number of
positive and negative integers.Return the answer array in such a way that the
given conditions are met:



Every consecutive pair of integers have opposite signs.


For all integers with the same sign, the order in which they were present in
nums is preserved.


The rearranged array begins with a positive integer.

Example 1

Input : nums = [2, 4, 5, -1, -3, -4]

Output : [2, -1, 4, -3, 5, -4]

Explanation:

The positive number 2, 4, 5 maintain their relative positions and -1, -3, -4
maintain their relative positions

Example 2

Input : nums = [1, -1, -3, -4, 2, 3]

Output : [1, -1, 2, -3, 3, -4]

Explanation:

The positive number 1, 2, 3 maintain their relative positions and -1, -3, -4
maintain their relative positions
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // every even index should have positive number

  vector<int> rearrangeArray(vector<int> &nums) {
    vector<int> positive_num;
    vector<int> negative_num;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < 0) {
        negative_num.push_back(nums[i]);
      } else {
        positive_num.push_back(nums[i]);
      }
    }

    int index = 0;
    for (int i = 0; i < nums.size() / 2; i++) {
      nums[index++] = positive_num[i];
      nums[index++] = negative_num[i];
    }
    return nums;
  }
};

int main() {
  cout << "Rearrange array elements by sign" << endl;
  vector<int> nums = {1, -1, -3, -4, 2, 3};
  Solution sol;
  sol.rearrangeArray(nums);
  for (auto &m : nums) {
    cout << m << " ";
  }
  return 0;
}