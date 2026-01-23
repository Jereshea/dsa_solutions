/******************************************************************************

Longest Consecutive Sequence in an Array

Given an array nums of n integers.



Return the length of the longest sequence of consecutive integers. The integers
in this sequence can appear in any order.


Example 1

Input: nums = [100, 4, 200, 1, 3, 2]

Output: 4

Explanation:

The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which
has a length of 4. This sequence can be formed regardless of the initial order
of the elements in the array.

Example 2

Input: nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]

Output: 9

Explanation:

The longest sequence of consecutive elements in the array is [0, 1, 2, 3, 4, 5,
6, 7, 8], which has a length of 9.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {

    if (nums.empty()) {
      return 0;
    }

    sort(nums.begin(), nums.end());
    int consecutive = 1;
    int max_consecutive = 1;

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i - 1] + 1 == nums[i]) {
        consecutive = consecutive + 1;
      } else {
        max_consecutive = max(max_consecutive, consecutive);
        consecutive = 1;
      }
    }

    return max(max_consecutive, consecutive);
  }
};

int main() {
  cout << "Longest Consecutive Sequence in an Array" << endl;
  vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  Solution sol;
  cout << sol.longestConsecutive(nums);
  return 0;
}