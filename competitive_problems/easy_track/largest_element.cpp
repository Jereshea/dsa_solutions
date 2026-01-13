#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int largestElement(vector<int> &nums) {
    int max_element = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
      max_element = max(max_element, nums[i]);
    }
    return max_element;
  }
};

int main() {
  vector<int> nums = {-4, -3, 0, 1, -8};
  Solution sol;
  int result = sol.largestElement(nums);
  cout << result;
  return 0;
}