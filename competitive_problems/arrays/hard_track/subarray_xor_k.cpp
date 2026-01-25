/******************************************************************************

Count subarrays with given xor K

Given an array of integers nums and an integer k, return the total number of
subarrays whose XOR equals to k.


Example 1

Input : nums = [4, 2, 2, 6, 4], k = 6



Output : 4



Explanation : The subarrays having XOR of their elements as 6 are [4, 2],  [4,
2, 2, 6, 4], [2, 2, 6], and [6]

Example 2

Input :nums = [5, 6, 7, 8, 9], k = 5



Output : 2



Explanation : The subarrays having XOR of their elements as 5 are [5] and [5, 6,
7, 8, 9]
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int subarraysWithXorK(vector<int> &nums, int k) {
    unordered_map<int, int> sum_frequeny;
    int sum = 0;
    int cnt = 0;
    sum_frequeny[0] = 1;

    for (int i = 0; i < nums.size(); i++) {

      sum = sum ^ nums[i];

      // Store it in the hash_map
      // 1 2 3 4   // Nums Array
      // 1 3 0 2  // sum values

      // Check if the subarray with the current limit also has the k
      int rem = sum ^ k;
      if (sum_frequeny.count(rem)) {
        cnt += sum_frequeny[rem];
      }

      sum_frequeny[sum]++;
    }
    return cnt;
  }
};
int main() {
  cout << "Count subarrays with given xor K" << endl;
  // vector<int> nums = {5, 6, 7, 8, 9};
  // int k = 5;
  vector<int> nums = {4, 2, 2, 6, 4};
  int k = 6;
  Solution sol;
  cout << sol.subarraysWithXorK(nums, k);

  return 0;
}