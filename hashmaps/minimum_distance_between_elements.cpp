/******************************************************************************

Minimum Distance Between Three Equal Elements I
Easy3 pt.
You are given an integer array nums.
A tuple (i, j, k) of 3 distinct indices is good if nums[i] == nums[j] ==
nums[k]. The distance of a good tuple is abs(i - j) + abs(j - k) + abs(k - i),
where abs(x) denotes the absolute value of x. Return an integer denoting the
minimum possible distance of a good tuple. If no good tuples exist, return -1.

Example 1:
Input: nums = [1,2,1,1,3]
Output: 6
Explanation:
The minimum distance is achieved by the good tuple (0, 2, 3).
(0, 2, 3) is a good tuple because nums[0] == nums[2] == nums[3] == 1. Its
distance is abs(0 - 2) + abs(2 - 3) + abs(3 - 0) = 2 + 1 + 3 = 6. Example 2:
Input: nums = [1,1,2,3,2,1,2]
Output: 8
Explanation:
The minimum distance is achieved by the good tuple (2, 4, 6).
(2, 4, 6) is a good tuple because nums[2] == nums[4] == nums[6] == 2. Its
distance is abs(2 - 4) + abs(4 - 6) + abs(6 - 2) = 2 + 2 + 4 = 8. Example 3:
Input: nums = [1]
Output: -1
Explanation:
There are no good tuples. Therefore, the answer is -1.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int main() {
  cout << "Minimum Distance between Three equal elements" << endl;
  vector<int> nums;
  nums = {1, 1, 2, 3, 2, 1, 2};
  unordered_map<int, pair<int, vector<int>>> map_value_count_index;

  for (int i = 0; i < nums.size(); i++) {
    map_value_count_index[nums[i]].first++;
    map_value_count_index[nums[i]].second.push_back(i);
  }

  int min_distance = INT_MAX;
  int distance = 0;

  bool flag = 0;
  for (auto &m : map_value_count_index) {
    if (m.second.first >= 3) {
      flag = 1;
      int i, j;

      for (i = 0; i < m.second.first - 2; i++) {
        for (j = i; j < i + 2; j++) {
          // Unordered key is used, so it will not be in order
          // cout<<endl<<"Value 1: "<<m.second.second[j]<<endl;
          // cout<<"Value 2: "<<m.second.second[j+1]<<endl;
          distance += abs(m.second.second[j] - m.second.second[j + 1]);
        }
        distance += abs(m.second.second[j] - m.second.second[i]);
        min_distance = min(min_distance, distance);
      }
    }
  }

  if (flag) {
    cout << min_distance << endl;
  } else {
    cout << "-1" << endl;
  }

  return 0;
}