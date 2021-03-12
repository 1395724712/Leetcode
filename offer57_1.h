#pragma once
/*
 * Copyrigth@wh
 * Author:wh
 * Date:20210312
 * Description:��һ���Ѿ����������У����Һ�Ϊs����������
 * Resolution: 1 һ��ָ��lָ�������,һ��rָ�����Ҷ�
 * 2 if *l+*r>s r--
 * 3 if *l+*r<s l++
 */
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int>::iterator leftVal = nums.begin();
		vector<int>::iterator rightVal = nums.end()-1;

		while(leftVal<rightVal)
		{
			if (*leftVal + *rightVal > target) rightVal--;
			else if (*rightVal + *leftVal < target) leftVal++;
			else return{ *rightVal,*leftVal };
		}
		return {};
	}
};