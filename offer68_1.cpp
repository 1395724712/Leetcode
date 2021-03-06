/**
* Copyright@wh
* Author:wh
* Description:二叉搜索树的公共祖先
* Resolution：和二叉树的那道题很像，而且我觉得我好像做过
*/

#include"TreeStruct.hpp"
#include<stdio.h>
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //终止递归
        if(root==NULL||root==p||root==q) return root;

        //递归进行
        if(root->val<p->val&&root->val<q->val) return lowestCommonAncestor(root->right, p, q);
        else if(root->val>p->val&&root->val>q->val) return lowestCommonAncestor(root->left, p, q);
        else return root;
    }
};