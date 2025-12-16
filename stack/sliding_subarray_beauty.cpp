/******************************************************************************

Sliding Subarray Beauty

Given an integer array nums containing n integers, find the beauty of each
subarray of size k.

The beauty of a subarray is the xth smallest integer in the subarray if it is
negative, or 0 if there are fewer than x negative integers.

Return an integer array containing n - k + 1 integers, which denote the beauty
of the subarrays in order from the first index in the array.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,-1,-3,-2,3], k = 3, x = 2
Output: [-1,-2,-2]
Explanation: There are 3 subarrays with size k = 3.
The first subarray is [1, -1, -3] and the 2nd smallest negative integer is -1.
The second subarray is [-1, -3, -2] and the 2nd smallest negative integer is -2.
The third subarray is [-3, -2, 3] and the 2nd smallest negative integer is -2.

Example 2:
Input: nums = [-3,1,2,-3,0,-3], k = 2, x = 1
Output: [-3,0,-3,-3,-3]
Explanation: There are 5 subarrays with size k = 2.
For [-3, 1], the 1st smallest negative integer is -3.
For [1, 2], there is no negative integer so the beauty is 0.
For [2, -3], the 1st smallest negative integer is -3.
For [-3, 0], the 1st smallest negative integer is -3.
For [0, -3], the 1st smallest negative integer is -3.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void sorted_stack(int num, stack<int> &stack_from_highest_to_lowest) {
  if (stack_from_highest_to_lowest.empty()) {
    stack_from_highest_to_lowest.push(num);
    return;
  }

  if (stack_from_highest_to_lowest.top() > num) {
    stack_from_highest_to_lowest.push(num);
    return;
  }

  int curr_element = stack_from_highest_to_lowest.top();
  stack_from_highest_to_lowest.pop();
  sorted_stack(num, stack_from_highest_to_lowest);
  stack_from_highest_to_lowest.push(curr_element);
}
void sliding_subarray(vector<int> &nums, int k, int x, vector<int> &result) {

  // Pushing all the elements to deque
  deque<int> dq;
  for (int i = 0; i < nums.size(); i++) {
    dq.push_back(nums[i]);
  }

  for (int i = 0; i < (nums.size() - k + 1); i++) {
    stack<int> stack_from_highest_to_lowest;
    int cnt = 0;
    for (int j = 0; j < k; j++) {
      int num = dq[j];
      sorted_stack(num, stack_from_highest_to_lowest);
    }

    // To get the xth smallest number
    while (cnt < x - 1) {
      stack_from_highest_to_lowest.pop();
      cnt++;
    }

    // Push it to the result
    if (stack_from_highest_to_lowest.top() < 0) {
      result.push_back(stack_from_highest_to_lowest.top());
    } else {
      result.push_back(0);
    }

    // Move to the next sliding window concept
    dq.pop_front();
  }
}

int main() {
  cout << "Redundant Operations" << endl;
  vector<int> nums = {1, -1, -3, -2, 3};
  int k = 3;
  int x = 2;
  vector<int> result;
  sliding_subarray(nums, k, x, result);

  // To print the result
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }

  return 0;
}