/******************************************************************************

Majority Element-II

Given an integer array nums of size n. Return all elements which appear more
than n/3 times in the array. The output can be returned in any order.


Example 1

Input: nums = [1, 2, 1, 1, 3, 2]

Output: [1]

Explanation:

Here, n / 3 = 6 / 3 = 2.

Therefore the elements appearing 3 or more times is : [1]

Example 2

Input: nums = [1, 2, 1, 1, 3, 2, 2]

Output: [1, 2]

Explanation:

Here, n / 3 = 7 / 3 = 2.

Therefore the elements appearing 3 or more times is : [1, 2]

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  /*
  vector<int> majorityElementTwo(vector<int>& nums) {
      int k=nums.size()/3;
      unordered_map<int,int> num_count;
      vector<int> result;

      for(int i=0;i<nums.size();i++){
          if(num_count[nums[i]] != -1){
              num_count[nums[i]]++;
              if(num_count[nums[i]] > k){
                  result.push_back(nums[i]);
                  // To avoid repetation of storage
                  num_count[nums[i]]=-1;
              }
          }
      }
      return result;
  }
  */
  vector<int> majorityElementTwo(vector<int> &nums) {
    int k = nums.size() / 3;
    unordered_map<int, int> num_count;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
      num_count[nums[i]]++;
      // To avoid repetation of storage
      if (num_count[nums[i]] == k + 1) {
        result.push_back(nums[i]);
      }
    }
    return result;
  }
};

int main() {
  cout << "Majority Element-II" << endl;
  vector<int> nums = {1, 2, 1, 1, 3, 2, 2};
  Solution sol;
  vector<int> result = sol.majorityElementTwo(nums);
  for (auto &m : result) {
    cout << m << " ";
  }
  return 0;
}