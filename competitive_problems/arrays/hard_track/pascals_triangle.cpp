/******************************************************************************

Pascal's Triangle I

Given two integers r and c, return the value at the rth row and cth column
(1-indexed) in a Pascal's Triangle.



In Pascal's triangle:



The first row contains a single element 1.


Each row has one more element than the previous row.


Every row starts and ends with 1.


For all interior elements (i.e., not at the ends), the value at position (r, c)
is computed as the sum of the two elements directly above it from the previous
row:

Pascal[r][c]=Pascal[r−1][c−1]+Pascal[r−1][c]
where indexing is 1-based

Example 1

Input: r = 4, c = 2

Output: 3

Explanation:

The Pascal's Triangle is as follows:

1

1 1

1 2 1

1 3 3 1

....

Thus, value at row 4 and column 2 = 3

Example 2

Input: r = 5, c = 3

Output: 6

Explanation:

The Pascal's Triangle is as follows:

1

1 1

1 2 1

1 3 3 1

1 4 6 4 1

....

Thus, value at row 5 and column 3 = 6

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int pascalTriangleI(int r, int c) {

    if (c == 0 || c == r - 1) {
      return 1;
    }

    vector<vector<int>> result;

    int col_values = 1;
    for (int i = 0; i < r; i++) {
      vector<int> curr_result;
      for (int j = 0; j < col_values; j++) {
        if ((j == 0) || (j == col_values - 1)) {
          curr_result.push_back(1);
        } else {
          curr_result.push_back(result[i - 1][j - 1] + result[i - 1][j]);
        }
      }
      col_values = col_values + 1;
      result.push_back(curr_result);
    }

    for (auto &m : result) {
      for (auto &x : m) {
        cout << x << " ";
      }
      cout << endl;
    }
    cout << endl;
    return result[r - 1][c - 1];
  }
};

int main() {
  cout << "Pascal's Triangle I" << endl;
  int r = 5;
  int c = 3;
  Solution sol;
  cout << sol.pascalTriangleI(r, c);
  return 0;
}