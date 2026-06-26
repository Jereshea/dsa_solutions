/******************************************************************************

Given an array of integers nums and an integer target. Return the indices(0 -
indexed) of two elements in nums such that they add up to target.



Each input will have exactly one solution, and the same element cannot be used
twice.


Example 1

Input: nums = [1, 6, 2, 10, 3], target = 7

Output: [0, 1]

Explanation:

nums[0] + nums[1] = 1 + 6 = 7

Example 2

Input: nums = [1, 3, 5, -7, 6, -3], target = 0

Output: [1, 5]

Explanation:

nums[1] + nums[5] = 3 + (-3) = 0
*******************************************************************************/

/******************************************************************************

Two Sum Problem
Input: nums = [1, 6, 2, 10, 3], target = 7


*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
// Time Complexity: n+nlogn
class solution{
    public:
    vector<int> find_index(vector<int> nums, int target){
        unordered_map<int,int> val_index;
        for(int i=0;i<nums.size();i++){
            val_index[nums[i]]=i;
        }
        
        sort(nums.begin(),nums.end());
        
        int left=0;
        int right=nums.size()-1;
        while(left != right){
            int sum=nums[left]+nums[right];
            if(sum==target){
                return {val_index[nums[left]],val_index[nums[right]]};
            }
            else if(sum<target){
                left++;
            }else{
                right--;
            }
        }
        return {-1,-1};
    }
    
};
*/

// Time Complexity: n [Approach: check if target-nums[i] is present in the map]
class solution{
    public:
    vector<int> find_index(vector<int> nums, int target){
        unordered_map<int,int> val_index;
        for(int i=0;i<nums.size();i++){
            val_index[nums[i]]=i;
        }
        

        for(int i=0;i<nums.size();i++){
            int complement=target-nums[i];
            if(val_index.find(complement)!=val_index.end()){
                return {i,val_index[complement]};
            }
        }
        return {-1,-1};
    }
    
};

int main(){
    vector<int> nums={1, 6, 2, 10, 3};
    int target=7;
    solution s;
    vector<int> result=s.find_index(nums, target);
    for(auto &m:result){
        cout<<m<<" ";
    }
}
