#pragma once
/*
 * Copyright@wh
 * Author:wh
 * Date:20210312
 * Description:数组中每一个数字都出现三次，只有一个数字出现了一次，找到这个数字
 * Resolution:1 位运算很巧妙
 * 2 时间复杂度为O(n)
 */
#include<vector>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		vector<int> bits(32, 0);
		for(auto num:nums)
		{//每个数字
			for(int i = 0;i<32;i++)
			{
				//逐位统计
				if (num & 1) bits[i]++;
				num = num >> 1;
			}
		}

		int res = 0;
		for(int i =31;i>=0;i--)
		{
			res += bits[i] % 3;
			res = res << 1;
		}

		return res;
	}
};