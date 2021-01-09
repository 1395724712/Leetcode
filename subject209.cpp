/*
*Copyright@wh
*Author:wh
*Date:20210109
*Description:给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组
*，并返回其长度。如果不存在符合条件的子数组，返回 0。
*Resolution:滑动窗口
*/

#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int resLength = INT32_MAX;//这是所求目标
        int subLength = 0;//这是窗口长度
        int sum = 0;//这是窗口内的和
        int i = 0;//这是滑动窗口的起始位置

        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];

            while(sum>=s){
                subLength = j - i + 1;
                resLength = resLength<subLength?resLength:subLength;
                sum -= nums[i++];
            }
        }
        

        return resLength = resLength<subLength?resLength:subLength;

    }
};