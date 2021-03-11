#pragma once
/*
 * Copyright@wh
 * Author:wh
 * Date:20210311
 * Description:和为s的连续正整数序列
 * Resolution:1 这个正整数序列的开头为 (s-(n-1)*n/2)/n 其中n为序列长度
 * 2 简化后为2*s>n^2-n 即n^2-n-2*s<0
 * 3 即枚举上述一元二次方程的两个根之间的整数，使得开头为正整数
 */
#include<vector>
#include<math.h>
using namespace std;
class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		int a = 1;
		int b = -1;
		int c = -2 * target;

		float root1 = (-1 * b + sqrt(pow(b, 2) - 4 * a*c)) / (2 * a);
		float root2 = (-1 * b - sqrt(pow(b, 2) - 4 * a*c)) / (2 * a);

		vector<vector<int>> res;
		
		//然后枚举零一下的部分
		for(int n = root1;n>=root2;n--)
		{
			float beg = (1.0*target - 1.0*(n - 1)*n / 2.0) / (1.0*n);
			//是否为整数
			if(beg<target&&beg-int(beg)==0)
			{
				vector<int> tmp;
				for(int i = 0;i<n;i++)
				{
					tmp.push_back(beg + i);
				}
				if (tmp.size() > 1) res.push_back(tmp);
			}
		}

		return res;
		
	}
};