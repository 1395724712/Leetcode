/**
* Copyright@wh
* Author:wh
* Description:二叉树的最近公共祖先
* Resolution:递归，返回公共祖先或者某一个目标节点
*/

#include"TreeStruct.hpp"
#include<stdio.h>
class Solution {
private:

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //终止条件
        if(root==NULL) return NULL;

        //左右查找值
        TreeNode* lRes = lowestCommonAncestor(root->left, p, q);
        TreeNode* rRes = lowestCommonAncestor(root->right, p, q);

        if(root==p||root==q){
            return root;//当前节点必为某一目标节点或者是公共祖先节点
        }
        if((lRes==p&&rRes==q)||(lRes==q&&rRes==p)){
            return root;//当前节点必为公共祖先节点
        }
        
        if(lRes!=NULL) return lRes;//lRes为目标节点或者是公共祖先节点
        else return rRes;//

    }
};