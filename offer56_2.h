#pragma once
/*
 * Copyright@wh
 * Author:wh
 * Date:20210312
 * Description:������ÿһ�����ֶ��������Σ�ֻ��һ�����ֳ�����һ�Σ��ҵ��������
 * Resolution:1 λ���������
 * 2 ʱ�临�Ӷ�ΪO(n)
 */
#include<vector>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		vector<int> bits(32, 0);
		for(auto num:nums)
		{//ÿ������
			for(int i = 0;i<32;i++)
			{
				//��λͳ��
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