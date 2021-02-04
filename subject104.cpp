/**
 * Copyright@wh
 * Author:wh
 * Date:20210204
 * Description:寻找二叉树的最大深度
 * Resolution:这个写递归吧
 * https://mp.weixin.qq.com/s/guKwV-gSNbA1CcbvkMtHBg
*/




struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        int maxDepth = leftDepth>rightDepth?leftDepth:rightDepth;
        return 1+maxDepth;
    }
};