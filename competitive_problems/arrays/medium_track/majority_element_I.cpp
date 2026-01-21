/******************************************************************************

Majority Element-I

Given an integer array nums of size n, return the majority element of the array.



The majority element of an array is an element that appears more than n/2 times
in the array. The array is guaranteed to have a majority element.


Example 1

Input: nums = [7, 0, 0, 1, 7, 7, 2, 7, 7]

Output: 7

Explanation:

The number 7 appears 5 times in the 9 sized array

Example 2

Input: nums = [1, 1, 1, 2, 1, 2]

Output: 1

Explanation:

The number 1 appears 4 times in the 6 sized array
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    unordered_map<int, int> num_count;

    int result_count = INT_MIN;
    int result_val = -1;
    for (int i = 0; i < nums.size(); i++) {
      num_count[nums[i]]++;
      if (num_count[nums[i]] > result_count) {
        result_count = num_count[nums[i]];
        result_val = nums[i];
      }
    }
    return result_val;
  }
};

int main() {
  cout << "Majority Element-I" << endl;
  vector<int> nums = {7, 0, 0, 1, 7, 7, 2, 7, 7};
  Solution sol;
  int result = sol.majorityElement(nums);
  cout << result;

  return 0;
}