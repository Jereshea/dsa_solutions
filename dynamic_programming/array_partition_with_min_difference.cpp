int abs_min = INT_MAX;
int total_sum = 0;
int curr_sum = 0;
for (int i = 0; i < n; i++) {
  total_sum += arr[i];
}
vector<vector<int>> dp_array(n, vector<int>(total_sum + 1, INT_MAX));
return min_difference(arr, n, 0, total_sum, curr_sum, abs_min, dp_array);