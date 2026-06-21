/******************************************************************************

Longest subarray with sum K:

Given an array nums of size n and an integer k, find the length of the longest
sub-array that sums to k. If no such sub-array exists, return 0.


Example 1

Input: nums = [10, 5, 2, 7, 1, 9],  k=15

Output: 4

Explanation:

The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length
of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its
elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array
is 4.

Example 2

Input: nums = [-3, 2, 1], k=6

Output: 0

Explanation:

There is no sub-array in the array that sums to 6. Therefore, the output is 0.
*******************************************************************************/

class solution{
    public:
    void k_places(vector<int> &nums, int k){
        int sum=0;
        int max_len=0;
        map<int, int> pre_sum;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k){
                max_len=max(max_len, i+1);
            }
            
            int rem=sum-k;
            if(pre_sum.find(rem)!=pre_sum.end()){
                max_len=max(max_len,i-pre_sum[rem]);
            }
            
            if(pre_sum.find(sum)==pre_sum.end()){
                pre_sum[sum]=i;
            }
        }
        cout<<max_len<<endl;
    }
    
};

int main()
{
    cout<<"Rotate Places"<<endl;
    int k=15;
    vector<int> nums={10, 5, 2, 7, 1, 9};
    solution s;
    s.k_places(nums, k);

    return 0;
}
