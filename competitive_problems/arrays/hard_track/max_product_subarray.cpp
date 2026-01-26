/************************
Maximum Product Subarray in an Array

Given an integer array nums. Find the subarray with the largest product, and
return the product of the elements present in that subarray.



A subarray is a contiguous non-empty sequence of elements within an array.


Example 1

Input: nums = [4, 5, 3, 7, 1, 2]

Output: 840

Explanation:

The largest product is given by the whole array itself

Example 2

Input: nums = [-5, 0, -2]

Output: 0

Explanation:

The largest product is achieved with the following subarrays [0], [-5, 0], [0,
-2], [-5, 0, -2].
***************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {

    // Traverse from left to right
    int product = 1;
    int product_1 = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
      product *= nums[i];
      if (product == 0) {
        product_1 = max(product_1, product);
        product = 1;
      } else {
        product_1 = max(product_1, product);
      }
    }

    // Traverse from right to left
    product = 1;
    int product_2 = INT_MIN;
    for (int i = nums.size() - 1; i >= 0; i--) {
      product *= nums[i];
      if (product == 0) {
        product_2 = max(product_2, product);
        product = 1;
      } else {
        product_2 = max(product_2, product);
      }
    }

    return max(product_1, product_2);
  }
};

int main() {
  // your code goes here
  cout << "Maximum Product Subarray in an Array" << endl;
  vector<int> nums = {4, 5, 3, 7, 1, 2};
  Solution sol;
  cout << sol.maxProduct(nums);
  return 0;
}
