/******************************************************************************

Count subarrays with given sum

Given an array of integers nums and an integer k, return the total number of
subarrays whose sum equals to k.


Example 1

Input: nums = [1, 1, 1], k = 2

Output: 2

Explanation: In the given array [1, 1, 1], there are two subarrays that sum up
to 2: [1, 1] and [1, 1]. Hence, the output is 2.

Example 2

Input: nums = [1, 2, 3], k = 3

Output: 2

Explanation: In the given array [1, 2, 3], there are two subarrays that sum up
to 3: [1, 2] and [3]. Hence, the output is 2.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void count_sub_array(vector<int> &nums, int k, int &count) {

    for (int i = 0; i < nums.size(); i++) {
      int curr_sum = 0;
      for (int j = i; j < nums.size(); j++) {
        curr_sum += nums[j];
        if (curr_sum == k) {
          count = count + 1;
        }
      }
    }
  }
  int subarraySum(vector<int> &nums, int k) {
    int count = 0;
    count_sub_array(nums, k, count);

    return count;
  }
};

int main() {
  cout << "Count subarrays with given sum" << endl;
  vector<int> nums = {1, 1, 1};
  int k = 2;
  Solution sol;
  cout << sol.subarraySum(nums, k);

  return 0;
}