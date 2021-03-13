/*
 * Copyright@wh
 * Author:wh
 * Date:20210313
 * Description:数组中每个数字都出现两次，只有两个数字只出现了一次，找到这两个数字，要求时间复杂度O(n),空间复杂度O(1)
 * Resolution: 1 依据，如果数组中每个数组都出现两次，只有一个数字出现了一次，那整体依次做异或即可
 * 2 如果有两个只出现一次的数字，则要分组做异或，异或的结果即为不同的这两个数字
 * 3 分组依据：先整体做异或，然后根据不为0的第i位为分组依据，将不同的两个数字分到不同的两组
 */
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		//首先确定分组依据
		int ref = 0;
		//整体异或
		for(auto elem:nums)
		{
			ref = ref ^ elem;
		}

		//找到不为0的i位
		int loc = 0;
		for(;loc<32;loc++)
		{
			if (ref & 1 == 1)
			{
				//当前位为1
				ref = ref & 1;//只保留当前位
				break;
			}
			ref = ref >> 1;
		}
		//恢复到原来的位置
		for(;loc>0;loc--)
		{
			ref = ref << 1;
		}

		int res1 = 0;
		int res2 = 0;

		for(auto num:nums)
		{
			//分组异或
			if (num&ref)
				res1 = res1 ^ num;
			else
				res2 = res2 ^ num;
		}
		return { res1,res2 };
		
	}
};