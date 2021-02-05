/**
 * Copyright@wh
 * Author:wh
 * Date:20210204
 * Description:二叉树的最小深度
 * Resolution:其实就是去找左右子树均为NULL的位置
 * https://mp.weixin.qq.com/s/BH8-gPC3_QlqICDg7rGSGA
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
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        
        if(!root->left&&!root->right){
            return 1;
        }
        else if(!root->left){
            return 1+minDepth(root->right);
        }
        else if(!root->right){
            return 1+minDepth(root->left);
        }
        else{
            int depthL = minDepth(root->left);
            int depthR = minDepth(root->right);
            int dep = depthL<depthR?depthL:depthR;
            return 1+dep;
        }
    }
};