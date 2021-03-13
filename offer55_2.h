/*
 * Copyright@wh
 * Author:wh
 * Date:20210313
 * Description:�ж�һ�����Ƿ�Ϊƽ�������
 * Resolution:�ݹ� �������
 * 1 ����������������ȣ���Ȼ������Ǹ���Ϊ��ǰ�ڵ����ȷ���
 * 2 ��Ҫ��������������ƽ���ж�
 */
#include"TreeStruct.hpp"

class Solution {
private:
	bool midTravelCheck(TreeNode* root, int& dep)
	{
		/*
		 * ������rootΪ��ǰ�ڵ㣬depΪ���ص����
		 */
		dep = 0;
		//�ݹ���ֹ����
		if (root == 0) return true;

		dep++;
		int leftDep, rigthDep;
		bool leftVal = midTravelCheck(root->left, leftDep);
		bool rightVal = midTravelCheck(root->right, rigthDep);

		dep = leftDep > rigthDep ? leftDep + dep : rigthDep + dep;

		if (leftDep > rigthDep + 1 || leftDep < rigthDep - 1) return false;
		return leftVal && rightVal;
	}
public:
	bool isBalanced(TreeNode* root) {
		int notUse;
		return midTravelCheck(root, notUse);
	}
};