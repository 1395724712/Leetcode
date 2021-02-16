/**
 * Copyright@wh
 * Author:wh
 * Date:20210216
 * Descripion:二叉搜索树的搜索
 * Resolution:搜个元素还不简单吗
*/

#include"TreeStruct.hpp"
#include<stdio.h>
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root||root->val==val){
            return root;
        }
        if(root->val>val){
            return searchBST(root->left,val);
        }
        if(root->val<val){
            return searchBST(root->right,val);
        }
        return NULL;
    }
};