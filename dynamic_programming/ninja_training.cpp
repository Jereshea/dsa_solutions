/******************************************************************************
Ninja's Training

Ninja is planing this 'N' days-long training schedule. Each day, he can perform
any one of these three activities. (Running, Fighting Practice or Learning New
Moves). Each activity has some merit points on each day. As Ninja has to improve
all his skills, he can't do the same activity in two consecutive days. Can you
help Ninja find out the maximum merit points Ninja can earn? You are given a 2D
array of size N*3 'POINTS' with the points corresponding to each day and
activity. Your task is to calculate the maximum number of merit points that
Ninja can earn. For Example If the given 'POINTS' array is [[1,2,5],
[3,1,1],[3,3,3]],the answer will be 11 as 5 + 3 + 3.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
// Recursion
int ninjas_training_recursion(vector<vector<int>> &points, int days, int task,
int last_task){ if(days==0){ int maxi=INT_MIN; for(int i=0; i<task; i++){ if(i!=
last_task){ maxi=max(maxi, points[days][i]);
            }
        }

        return maxi;
    }

    int maxi=INT_MIN;
    for(int i=0; i<task; i++){
        if(i!=last_task){
            int point=points[days][i]+ninjas_training_recursion(points, days-1,
task, i); maxi=max(maxi, point);
        }
    }
    return maxi;
}
*/

int ninjas_training_memoization(vector<vector<int>> &points, int days, int task,
                                int last_task, vector<vector<int>> &dp_array) {
  if (days == 0) {
    int maxi = 0;
    for (int i = 0; i < task; i++) {
      if (i != last_task) {
        maxi = max(maxi, points[0][i]);
      }
    }
    dp_array[0][last_task] = maxi;
    return maxi;
  }

  if (dp_array[days][last_task] != -1) {
    return dp_array[days][last_task];
  }

  int maxi = 0;
  for (int i = 0; i < task; i++) {
    if (i != last_task) {
      int point = points[days][i] + ninjas_training_memoization(
                                        points, days - 1, task, i, dp_array);
      maxi = max(maxi, point);
    }
  }
  dp_array[days][last_task] = maxi;
  return dp_array[days][last_task];
}

/*
int ninjas_training_tabulation(vector<vector<int>> &points, int days, int task,
int last_task, vector<vector<int>> &dp_array){

    dp_array[0][0]=max(points[0][1],points[0][2]);
    dp_array[0][1]=max(points[0][0],points[0][2]);
    dp_array[0][2]=max(points[0][1],points[0][0]);
    dp_array[0][3]=max(points[0][1],max(points[0][0],points[0][2]));


    for(int day=1;day<=days;day++){
        for(int last_task=0;last_task<=task;last_task++){
            dp_array[day][last_task]=0;
            int maxi=0;
            for(int i=0; i<task; i++){
                if(i!=last_task){
                    int point=points[day][i]+dp_array[day-1][i];
                    dp_array[day][last_task]=max(dp_array[day][last_task],
point);
                }
            }
        }
    }
    return dp_array[days][task];
}
*/
int main() {
  cout << "Ninja's Training" << endl;
  vector<vector<int>> points = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
  int days = 2;
  int task = 3;
  // cout<<ninjas_training_recursion(points, days, task, task);
  vector<vector<int>> dp_array(days + 1, vector<int>(task + 1, -1));
  cout << ninjas_training_memoization(points, days, task, task, dp_array);
  // vector<vector<int>> dp_array(days+1,vector<int>(task+1, -1));
  // cout<<ninjas_training_tabulation(points, days, task, task, dp_array);

  return 0;
}
