/**
 * Copyright@wh
 * Author:wh
 * Date:20210207
 * Description:路径总和==目标路径
 * Resolution:https://mp.weixin.qq.com/s/6TWAVjxQ34kVqROWgcRFOg
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        //结束条件
        if(!root){
            return false;
        }
        //单层逻辑
        if(!root->left&&!root->right&&root->val==targetSum){
            return true;
        }


        bool leftVal = false;
        if(root->left){
            leftVal = hasPathSum(root->left,targetSum-root->val);
        }
        bool rightVal = false;
        if(root->right){
            rightVal = hasPathSum(root->right,targetSum-root->val);
        }
        
        return leftVal||rightVal;
    }
};