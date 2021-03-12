#pragma once
/*
 * Copyrigth@wh
 * Author:wh
 * Date:20210312
 * Description:在一个已经升序序列中，查找和为s的两个数字
 * Resolution: 1 一个指针l指向最左端,一个r指向最右端
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