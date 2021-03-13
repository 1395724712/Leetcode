/*
 * Copyright@wh
 * Author:wh
 * Date:20210313
 * Descitpion:树的最大深度
 * Resolution: 迭代，层次遍历
 */
#include "TreeStruct.hpp"
#include<stack>
#include<queue>
using namespace std;
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;
		queue<TreeNode*> sta;
		sta.push(root);
		int dep = 0;
		while(!sta.empty())
		{
			int len = sta.size();
			for(int i =0;i<len;i++)
			{
				TreeNode *node = sta.front();
				sta.pop();
				if (node->left != NULL) sta.push(node->left);
				if (node->right != NULL) sta.push(node->right);
			}
			dep++;
		}
		return dep;
	}
};