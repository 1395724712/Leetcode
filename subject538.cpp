/**
 * Copyright@wh
 * Author:wh
 * Date:20210219
 * Decription:二叉树转变为累加树
 * Reslution:就是一个先右后左的中序遍历
*/

class Solution {
private:
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        //终止条件
        if(root==NULL){
            return root;
        }
        //右
        convertBST(root->right);
        //中
        root->val = root->val +sum;
        sum = root->val;
        //左
        convertBST(root->left);
        return root;
    }
};