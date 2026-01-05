/**********
Problem statement
You have been given the start and end times of 'N' intervals. Write a function
to check if any two intervals overlap with each other.

Note :
If an interval ends at time T and another interval starts at the same time, they
are not considered overlapping intervals. Detailed explanation ( Input/output
format, Notes, Images ) Constraints : 1 <= T <= 10^2 0 <= N <= 10^5 0 <=
Start[i] <= 10^15 1 <= End[i] <= 10^15

Time Limit: 1 sec
Sample Input 1 :
1
3
1 2 3
2 3 4
Sample Output 1 :
false
Explanation For Sample Input 1:
Here, in given intervals [1, 2], [2, 3], [3, 4], there are no overlapping
intervals present. Sample Input 2 :
2
1
100
200
2
2 1
3 4
Sample Output 2 :
false
true
***********/

#include <bits/stdc++.h>
using namespace std;
/*
checkOverlappingIntervals(long* start, long* end, int n)
{
    //Write your code here
    if(n<=1){
        return false;
    }
    vector<vector<long>> start_end;

    for(int i=0;i<n;i++){
        start_end.push_back({start[i],end[i]});
    }

    sort(start_end.begin(),start_end.end());
    long prev_start=start_end[0][0];
    long prev_end=start_end[0][1];

    for(int i=1;i<n;i++){
        long curr_start=start_end[i][0];
        long curr_end=start_end[i][1];

        if(prev_end>curr_start){
            return true;
        }

        prev_start=curr_start;
        prev_end=curr_end;
    }
    return false;
}
*/

bool checkOverlappingIntervals(long *start, long *end, int n) {
  // Write your code here
  if (n <= 1) {
    return false;
  }
  vector<pair<long, long>> start_end;

  for (int i = 0; i < n; i++) {
    pair<long, long> pair_1 = make_pair(start[i], end[i]);
    start_end.push_back(pair_1);
  }

  sort(start_end.begin(), start_end.end());
  long prev_start = start_end[0].first;
  long prev_end = start_end[0].second;

  for (int i = 1; i < n; i++) {
    long curr_start = start_end[i].first;
    long curr_end = start_end[i].second;

    if (prev_end > curr_start) {
      return true;
    }

    prev_start = curr_start;
    prev_end = curr_end;
  }
  return false;
}

int main() {
  int n = 3;
  long start[n] = {2, 1, 3};
  long end[n] = {3, 2, 4};
  // int n=5;
  // long start[n]={1,2,3,4,5};
  // long end[n]={9,3,4,5,6};
  cout << checkOverlappingIntervals(start, end, n);
}