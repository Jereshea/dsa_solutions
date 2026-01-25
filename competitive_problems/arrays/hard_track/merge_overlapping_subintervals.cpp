/******************************************************************************

Merge Overlapping Subintervals

Given an array of intervals where intervals[i] = [starti, endi], merge all
overlapping intervals and return an array of the non-overlapping intervals that
cover all the intervals in the input.



You can return the intervals in any order.


Example 1

Input: intervals = [[1,5],[3,6],[8,10],[15,18]]

Output: [[1,6],[8,10],[15,18]]

Explanation: Intervals [1,5] and [3,6] overlap, so they are merged into [1,6].

Example 2

Input: intervals = [[5,7],[1,3],[4,6],[8,10]]

Output: [[1,3],[4,7],[8,10]]

Explanation: Intervals [4,6] and [5,7] overlap and are merged into [4,7].
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> mergeOverlap(vector<vector<int>> &arr) {
    // Your code goes here
    vector<vector<int>> result;
    sort(arr.begin(), arr.end());

    // for(auto &m: arr){
    //     for(auto &x:m){
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }

    int ptr1 = 1;
    int ptr_result = 0;
    result.push_back({arr[0][0], arr[0][1]});
    while (ptr1 < arr.size()) {
      if (arr[ptr1][0] > result[ptr_result][0] &&
          arr[ptr1][0] <= result[ptr_result][1]) {
        result[ptr_result][1] = max(arr[ptr1][1], result[ptr_result][1]);
      } else {
        result.push_back({arr[ptr1][0], arr[ptr1][1]});
        ptr_result = ptr_result + 1;
      }
      ptr1++;
    }

    return result;
  }
};

int main() {
  cout << "Merge Overlapping Subintervals" << endl;
  vector<vector<int>> arr = {{5, 7}, {1, 3}, {4, 6}, {8, 10}};
  Solution sol;
  vector<vector<int>> result = sol.mergeOverlap(arr);
  for (auto &m : arr) {
    for (auto &x : m) {
      cout << x << " ";
    }
    cout << endl;
  }
  cout << endl << endl;
  for (auto &m : result) {
    for (auto &x : m) {
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}