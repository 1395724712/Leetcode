/*
*Copyright:wh
*Author:wh
*Date:20210109
*Description:给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
*Resolution:双指针:https://mp.weixin.qq.com/s?__biz=MzUxNjY5NTYxNA==&mid=2247484250&idx=1&sn=223e601c74ac9690cf523fba81529df1&scene=21#wechat_redirect
*/

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        //先排序
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            //如果第一个元素就大于0，没有结果
            if(nums[i]>0){
                return res;
            }
            //重复元素
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            while(right>left){

                if(nums[i]+nums[left]+nums[right]>0){
                    right--;
                }
                else if(nums[i]+nums[left]+nums[right]<0){
                    left++;
                }
                else{
                    res.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    //找到目标，继续推进
                    while(right>left&&nums[right-1]==nums[right]) right--;
                    while(right>left&&nums[left+1]==nums[left]) left++;
                    right--;
                    left++;
                }

            }
        }
        
        return res;

    }
};