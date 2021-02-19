/**
 * Copyright@wh
 * Author:wh
 * Date:20210219
 * Description:二叉树修剪
 * Resolution:递归吧
*/

#include"TreeStruct.hpp"

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==NULL){
            return root;
        }
        
        if(root->val>high){
            //根节点超过范围，舍弃右子树和根节点
            return trimBST(root->left,low,high);
        }
        else if(root->val<low){
            //根节点小于下限，舍弃左子树和根节点
            return trimBST(root->right,low,high);
        }

        //根节点在要求的范围内
        root->left = trimBST(root->left,low,high);
        root->right = trimBST(root->right,low,high);

        return root;
    }
};