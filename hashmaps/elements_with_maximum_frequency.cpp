/******************************************************************************
ELEMENTS WITH MAXIMUM FREQUENCY:
You are given an array nums consisting of positive integers.

Return the total frequencies of elements in nums such that those elements all
have the maximum frequency.

The frequency of an element is the number of occurrences of that element in the
array.

Example 1:

Input: nums = [1,2,2,3,1,4]
Output: 4
Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum
frequency in the array. So the number of elements in the array with maximum
frequency is 4. Example 2:

Input: nums = [1,2,3,4,5]
Output: 5
Explanation: All elements of the array have a frequency of 1 which is the
maximum. So the number of elements in the array with maximum frequency is 5.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxFrequencyElements(vector<int> &nums) {
    unordered_map<int, int> frequency_table;
    int frequency = 0;
    int frequency_val = 0;
    for (int i = 0; i < nums.size(); i++) {
      frequency_table[nums[i]]++;

      if (frequency_table[nums[i]] > frequency_val) {
        frequency_val = frequency = frequency_table[nums[i]];
      } else if (frequency_table[nums[i]] == frequency_val) {
        frequency += frequency_table[nums[i]];
      }
    }
    return frequency;
  }
};

int main() {
  cout << "Elements with Maximum Frequency" << endl;
  vector<int> nums = {1, 2, 2, 3, 1, 4};
  // vector<int> nums={1, 2, 3, 4, 5};
  Solution sol;
  cout << sol.maxFrequencyElements(nums);
  return 0;
}