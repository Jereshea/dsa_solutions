#include <bits/stdc++.h>
using namespace std;
/*
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 1

1 0 1 0 0
1 0 1 1 1
1 1 1 2 2
1 0 0 1 2


area=2

neraby all 1?&& curr==1 min of all+1
*/

int find_max_area(vector<vector<int>> &MAT, int n, int m) {
  vector<vector<int>> dp_array(n, vector<int>(m, -1));
  int area = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 || j == 0) {
        dp_array[i][j] = MAT[i][j];
        area = max(area, dp_array[i][j]);
      } else {
        if (dp_array[i - 1][j] > 0 && dp_array[i - 1][j - 1] > 0 &&
            dp_array[i][j - 1] > 0) {
          int adj_min = min(dp_array[i - 1][j],
                            min(dp_array[i - 1][j - 1], dp_array[i][j - 1]));
          if (MAT[i][j] != 0) {
            dp_array[i][j] = adj_min + 1;
            area = max(area, dp_array[i][j]);
          } else {
            dp_array[i][j] = 0;
            area = max(area, dp_array[i][j]);
          }
        } else {
          dp_array[i][j] = MAT[i][j];
          area = max(area, dp_array[i][j]);
        }
      }
    }
  }

  // for(auto &m:dp_array){
  //     for(auto &k:m){
  //         cout<<k<<" ";
  //     }
  //     cout<<endl;
  // }

  return area * area;
}
int maximumAreaSquare(vector<vector<int>> &MAT, int n, int m) {
  /*
  1 1 1 1
  1 1 1 1
  1 1 1 1

  1 1 1 1
  1 2 2 2
  1 2 3 3
  1
  */
  // Write your code here.
  return find_max_area(MAT, n, m);
}
