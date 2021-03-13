/*
 * Copyright@wh
 * Author:wh
 * Date:20210313
 * Description:������ÿ�����ֶ��������Σ�ֻ����������ֻ������һ�Σ��ҵ����������֣�Ҫ��ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
 * Resolution: 1 ���ݣ����������ÿ�����鶼�������Σ�ֻ��һ�����ֳ�����һ�Σ���������������򼴿�
 * 2 ���������ֻ����һ�ε����֣���Ҫ������������Ľ����Ϊ��ͬ������������
 * 3 �������ݣ������������Ȼ����ݲ�Ϊ0�ĵ�iλΪ�������ݣ�����ͬ���������ֵַ���ͬ������
 */
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		//����ȷ����������
		int ref = 0;
		//�������
		for(auto elem:nums)
		{
			ref = ref ^ elem;
		}

		//�ҵ���Ϊ0��iλ
		int loc = 0;
		for(;loc<32;loc++)
		{
			if (ref & 1 == 1)
			{
				//��ǰλΪ1
				ref = ref & 1;//ֻ������ǰλ
				break;
			}
			ref = ref >> 1;
		}
		//�ָ���ԭ����λ��
		for(;loc>0;loc--)
		{
			ref = ref << 1;
		}

		int res1 = 0;
		int res2 = 0;

		for(auto num:nums)
		{
			//�������
			if (num&ref)
				res1 = res1 ^ num;
			else
				res2 = res2 ^ num;
		}
		return { res1,res2 };
		
	}
};