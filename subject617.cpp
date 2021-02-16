/**
 * Copyright@wh
 * Author:wh
 * Date:20210216
 * Description:合并二叉树
 * Resolution:不用释放节点还是挺不错的
 * https://mp.weixin.qq.com/s/3f5fbjOFaOX_4MXzZ97LsQ
*/

#include "TreeStruct.hpp"

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        //终止条件
        if(!root1){
            return root2;
        }
        if(!root2){
            return root1;
        }

        //单步逻辑
        TreeNode* root = new TreeNode;
        root->val = root1->val + root2->val;
        root->left = mergeTrees(root1->left,root2->left);
        root->right = mergeTrees(root1->right,root2->right);

        return root;
    }
};