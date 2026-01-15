/******************************************************************************
Second Largest Element:

Given an array of integers nums, return the second-largest element in the array.
If the second-largest element does not exist, return -1.


Example 1

Input: nums = [8, 8, 7, 6, 5]

Output: 7

Explanation:

The largest value in nums is 8, the second largest is 7

Example 2

Input: nums = [10, 10, 10, 10, 10]

Output: -1

Explanation:

The only value in nums is 10, so there is no second largest value, thus -1 is
returned

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int secondLargestElement(vector<int> &nums) {
    // your code goes here

    int firstLargestElement = INT_MIN;
    int secondLargestElement = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > firstLargestElement) {
        secondLargestElement = firstLargestElement;
        firstLargestElement = nums[i];
      } else if (nums[i] < firstLargestElement &&
                 nums[i] > secondLargestElement) {
        secondLargestElement = nums[i];
      }
    }
    if (secondLargestElement == INT_MIN) {
      return -1;
    } else {
      return secondLargestElement;
    }
  }
};
int main() {
  vector<int> nums = {8, 8, 7, 6, 5};
  Solution sol;
  int result = sol.secondLargestElement(nums);
  cout << result;
  return 0;
}
