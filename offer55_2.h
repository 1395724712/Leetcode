/*
 * Copyright@wh
 * Author:wh
 * Date:20210313
 * Description:判断一棵树是否为平衡二叉树
 * Resolution:递归 中序遍历
 * 1 返回左右子树的深度，当然最深的那个作为当前节点的深度返回
 * 2 需要返回左右子树的平衡判断
 */
#include"TreeStruct.hpp"

class Solution {
private:
	bool midTravelCheck(TreeNode* root, int& dep)
	{
		/*
		 * 描述：root为当前节点，dep为返回的深度
		 */
		dep = 0;
		//递归终止条件
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