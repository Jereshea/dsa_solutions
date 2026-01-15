/******************************************************************************

Single Number - I

Given an array of nums of n integers. Every integer in the array appears twice
except one integer. Find the number that appeared once in the array.


Example 1

Input : nums = [1, 2, 2, 4, 3, 1, 4]

Output : 3

Explanation : The integer 3 has appeared only once.

Example 2

Input : nums = [5]

Output : 5

Explanation : The integer 5 has appeared only once.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    // your code goes here
    unordered_map<int, int> map_count;
    for (int i = 0; i < nums.size(); i++) {
      map_count[nums[i]]++;
    }

    int result = 0;
    for (auto &m : map_count) {
      if (m.second == 1) {
        return m.first;
      }
    }
    return result;
  }
};

int main() {
  cout << "Single Number - I" << endl;
  vector<int> nums = {1, 2, 2, 4, 3, 1, 4};
  Solution sol;
  cout << sol.singleNumber(nums);

  return 0;
}