/***********
Frog Jump

A frog wants to climb a staircase with n steps. Given an integer array heights,
where heights[i] contains the height of the ith step.



To jump from the ith step to the jth step, the frog requires abs(heights[i] -
heights[j]) energy, where abs() denotes the absolute difference. The frog can
jump from any step either one or two steps, provided it exists.



Return the minimum amount of energy required by the frog to go from the 0th step
to the (n-1)th step.


Example 1

Input: heights = [2, 1, 3, 5, 4]

Output: 2

Explanation:

One possible route can be,

0th step -> 2nd Step = abs(2 - 3) = 1

2nd step -> 4th step = abs(3 - 4) = 1

Total = 1 + 1 = 2.

Example 2

Input: heights = [7, 5, 1, 2, 6]

Output: 9

Explanation:

One possible route can be,

0th step -> 1st Step = abs(7 - 5) = 2

1st step -> 3rd step = abs(5 - 2) = 3

3rd step -> 4th step = abs(2 - 6) = 4

Total = 2 + 3 + 4 = 9.
*************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int frogJump_rec(vector<int> &heights, int index, int size) {

    if (index > size) {
      return INT_MAX;
    }

    if (index == size - 1) {
      return 0;
    }

    int step_1 = INT_MAX;
    int step_2 = INT_MAX;
    if (index + 1 < size) {
      step_1 = abs(heights[index] - heights[index + 1]) +
               frogJump_rec(heights, index + 1, size);
    }

    if (index + 2 < size) {
      step_2 = abs(heights[index] - heights[index + 2]) +
               frogJump_rec(heights, index + 2, size);
    }
    return min(step_1, step_2);
  }
  int frogJump(vector<int> &heights) {
    return frogJump_rec(heights, 0, heights.size());
  }
};

int main() {
  // your code goes here
  cout << "Frog Jump" << endl;
  vector<int> heights = {2, 1, 3, 5, 4};
  Solution sol;
  cout << sol.frogJump(heights);
}
