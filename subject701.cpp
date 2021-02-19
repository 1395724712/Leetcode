/**
 * Copyright@wh
 * Author:wh
 * Date:20210219
 * Description:在二叉搜索树中执行插入操作
 * Resolution:这个挺简单的呀，为啥是中等难度
*/

#include"TreeStruct.hpp"
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //终止条件，找到插入位置
        if(root==NULL){
            root = new TreeNode(val);
            return root;
        }

        //单层逻辑
        if(val>root->val){
            root->right = insertIntoBST(root->right,val);
        }
        else{
            root->left = insertIntoBST(root->left,val);
        }


        return root;
    }
};