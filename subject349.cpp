/**
 * Copyright@wh
 * Author:wh
 * Date:20210112
 * Description:给定两个数组，编写一个函数来计算它们的交集。
 * Resolution:unordered_set https://mp.weixin.qq.com/s/N9iqAchXreSVW7zXUS4BVA
*/

#include<vector>
#include<set>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        unordered_set<int> nums(nums1.begin(),nums1.end());
        //然后开始对比
        for (auto elem:nums2)
        {
            if(nums.find(elem)!=nums.end()){
                res.insert(elem);
            }
        }
        return vector<int>(res.begin(),res.end());
    }
};