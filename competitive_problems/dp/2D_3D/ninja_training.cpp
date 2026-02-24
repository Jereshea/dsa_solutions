/*********
Ninja's training:

A ninja has planned a n-day training schedule. Each day he has to perform one of
three activities - running, stealth training, or fighting practice. The same
activity cannot be done on two consecutive days and the ninja earns a specific
number of merit points, based on the activity and the given day.



Given a n x 3-sized matrix, where matrix[i][0], matrix[i][1], and matrix[i][2],
represent the merit points associated with running, stealth and fighting
practice, on the (i+1)th day respectively. Return the maximum possible merit
points that the ninja can earn.


Example 1

Input: matrix = [[10, 40, 70], [20, 50, 80], [30, 60, 90]]

Output: 210

Explanation:

Day 1: fighting practice = 70

Day 2: stealth training = 50

Day 3: fighting practice = 90

Total = 70 + 50 + 90 = 210

This gives the optimal points.

Example 2

Input: matrix = [[70, 40, 10], [180, 20, 5], [200, 60, 30]]

Output: 290

Explanation:

Day 1: running = 70

Day 2: stealth training = 20

Day 3: running = 200

Total = 70 + 20 + 200 = 290

This gives the optimal points.
**********************/
#include <bits/stdc++.h>
using namespace std;

/*
// Recursion
class Solution {
public:
    int ninja_recursive(int row, vector<vector<int>>& matrix, int
prev_training){

        if(row>= matrix.size()){
            return 0;
        }

        int include=INT_MIN;
        int max_points=0;
        for(int i=0; i<matrix[row].size();i++){
            if(i!=prev_training){
                include=matrix[row][i]+ninja_recursive(row+1,matrix, i);
                max_points=max(max_points,include);
            }
        }

        return max_points;
    }
    int ninjaTraining(vector<vector<int>>& matrix) {
        int result=INT_MIN;
        // for(int i=0;i<matrix[0].size();i++){
            result= max(result,ninja_recursive(0, matrix, -1));
        // }
        return result;

    }
};
*/
class Solution {
public:
  int ninja_recursive(int row, vector<vector<int>> &matrix, int prev_training,
                      vector<vector<int>> &dp) {

    if (row >= matrix.size()) {
      return 0;
    }

    if (dp[row][prev_training] != -1) {
      return dp[row][prev_training];
    }

    int include = INT_MIN;
    int max_points = 0;
    for (int i = 0; i < matrix[row].size(); i++) {
      if (i != prev_training) {
        include = matrix[row][i] + ninja_recursive(row + 1, matrix, i, dp);
        max_points = max(max_points, include);
      }
    }

    return dp[row][prev_training] = max_points;
  }
  int ninjaTraining(vector<vector<int>> &matrix) {
    int result = INT_MIN;
    // for(int i=0;i<matrix[0].size();i++){
    vector<vector<int>> dp(matrix.size(),
                           vector<int>(matrix[0].size() + 1, -1));
    result = max(result, ninja_recursive(0, matrix, matrix[0].size(), dp));
    // }
    return result;
  }
};
int main() {
  // your code goes here
  vector<vector<int>> matrix = {{70, 40, 10}, {180, 20, 5}, {200, 60, 30}};
  Solution sol;
  cout << sol.ninjaTraining(matrix);
}
