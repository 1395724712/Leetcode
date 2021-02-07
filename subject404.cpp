/**
 * Copyright@wh
 * Author:wh
 * Date:20210207
 * Description:左叶子节点的总和
 * Resolution:题解给出的逻辑更简单
 * https://mp.weixin.qq.com/s/gBAgmmFielojU5Wx3wqFTA
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
    int sumOfLeftLeaves(TreeNode* root) {
        //结束条件
        if(!root){
            return 0;
        }

        //单层逻辑
        int leftVal = sumOfLeftLeaves(root->left);
        int rightVal = sumOfLeftLeaves(root->right);

        int sum = 0;
        if(root->left&&!root->left->left&&!root->left->right){
            sum +=root->left->val;
        }

        return sum+leftVal+rightVal;
    }
};