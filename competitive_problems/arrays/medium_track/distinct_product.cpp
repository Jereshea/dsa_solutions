/******************************************************************************
Distinct Prime Factors of Product of Array:

Given an array of positive integers nums, return the number of distinct prime factors in the product of the elements of nums.

Note that:

A number greater than 1 is called prime if it is divisible by only 1 and itself.
An integer val1 is a factor of another integer val2 if val2 / val1 is an integer.
 

Example 1:

Input: nums = [2,4,3,7,10,6]
Output: 4
Explanation:
The product of all the elements in nums is: 2 * 4 * 3 * 7 * 10 * 6 = 10080 = 25 * 32 * 5 * 7.
There are 4 distinct prime factors so we return 4.
Example 2:

Input: nums = [2,4,8,16]
Output: 1
Explanation:
The product of all the elements in nums is: 2 * 4 * 8 * 16 = 1024 = 210.
There is 1 distinct prime factor so we return 1.
 

Constraints:

1 <= nums.length <= 104
2 <= nums[i] <= 1000
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int distinctPrimeFactors(vector<int>& nums) {
//         // Find the product of the elements in nums
//         int product=1;
//         for(int i=0;i<nums.size();i++){
//             product*=nums[i];
//         }
//         int act_product=product;
//         unordered_map<int,int> list;
//         int result=0;
//         while(product>1){
//             for(int i=2;i<=product;i++){
//                 if(product%i ==0){
//                     if(list[i]==0){
//                         list[i]=1;
//                         result=result+1;
//                     }
//                     product=product/i;
//                     break;
//                 }
//             }
//         }

//         return result;
//     }
// };
class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        // Find the product of the elements in nums
        int result=0;
        unordered_map<int,int> list;
        for(int i=0;i<nums.size();i++){
            int ind_num=nums[i];
            while(ind_num>1){
                for(int i=2;i<=ind_num;i++){
                    if(ind_num%i == 0){
                        if(list[i]==0){
                        list[i]=1;
                        result=result+1;
                    }
                    ind_num=ind_num/i;
                    break;
                    }
                }
            }
        }

        return result;
    }
};
int main()
{
    cout<<"Distinct Prime Factors of Product of Array"<<endl;
    vector<int> nums={2,4,3,7,10,6};
    Solution sol;
    cout<<sol.distinctPrimeFactors(nums);

    return 0;
}