/*
*Copyright:wh
*Author:wh
*Date:20210109
*Description:给定一个包含 n 个整数的数组 nums 和一个目标值 target，
*判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。\
*Resolution:双指针，在三数求和的基础上在加一层循环
*/

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());

        if(nums.size()<4){
            return res;
        }

        for (int k = 0; k < nums.size()-3; k++)
        {
            //如果存在重复的元素
            if(k>0&&nums[k]==nums[k-1]){
                continue;
            }
            for(int i=k+1;i<nums.size()-2;i++)
            {
                //如果存在重复的元素
                if(i>k+1&&nums[i]==nums[i-1]){
                    continue;
                }

                int left = i+1;
                int right = nums.size() - 1;
                while(left<right)
                {
                    if(nums[k]+nums[i]+nums[left]+nums[right]>target){
                        right--;
                    }
                    else if(nums[k]+nums[i]+nums[left]+nums[right]<target){
                        left++;
                    }
                    else{
                        res.push_back(vector<int>{nums[k],nums[i],nums[left],nums[right]});
                        //找到目标，继续推进
                        right--;
                        left++;
                        while(left<right&&nums[right]==nums[right+1]) right--;
                        while(left<right&&nums[left]==nums[left-1]) left++;

                    }
                }
            }
        }
        return res;
    }
};