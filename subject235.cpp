/**
* Copyright@wh
* Author:wh
* Date:20210219
* Description:二叉搜索树中寻找根节点
* Resolution:https://mp.weixin.qq.com/s/Ja9dVw2QhBcg_vV-1fkiCg
*/

#include"TreeStruct.cpp"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return root;
        }

        if(root->val>p->val&&root->val>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(root->val<p->val&&root->val<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        else{
            return root;
        }
    }
};