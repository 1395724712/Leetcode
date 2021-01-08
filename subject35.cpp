/*
*Copyright:wh
*Author:wh
*Date:20210108
*Description:给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
*Resolution:二分查找
*/

#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //初始化位置参数
        unsigned int beg;
        unsigned int end;
        if(target>nums[nums.size()/2])
        {
            beg = nums.size()/2;
            end = nums.size() - 1;
        }
        else
        {
            beg = 0;
            end = nums.size()/2;
        }
        
        
        while(beg!=end)
        {
            if(target>nums[beg+int(0.5+(end-beg)/2)])
            {
                beg =beg + (end - beg)/2;
            }
            else
            {
                end =end - (end - beg)/2;
            }

            if(beg == end -1)
            {
                if(target>nums[beg])
                {
                    beg = end;
                }
                else
                {
                    end = beg;
                }
                
            }
        }

        if(target<=nums[beg])
        {
            return beg;
        }
        else
        {
            return beg +1;
        }
        

    }
};