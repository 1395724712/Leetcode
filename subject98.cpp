/**
 * Copyright@wh
 * Author:wh
 * Date:20210216
 * Description:判断一个二叉树是不是二叉搜索树
 * Resolution:530的那个方法就挺不错的，我觉得比攻略给出的还要简单
 * https://mp.weixin.qq.com/s/8odY9iUX5eSi0eRFSXFD4Q
*/

#include "TreeStruct.hpp"
#include<stdio.h>

class Solution {
private:
    TreeNode* pre = NULL;
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        bool leftFlag = isValidBST(root->left);

        if(pre!=NULL&&pre->val>=root->val){
            return false;
        }

        pre = root;
        bool rightFlag = isValidBST(root->right);

        return leftFlag&&rightFlag;
    }
};