/**
 * Copyright@wh
 * Author:wh
 * Date:20210203
 * Description:反转二叉树
 * Reslution:使用递归法很简单，但我想用迭代来做
 * https://mp.weixin.qq.com/s/6gY1MiXrnm-khAAJiIb5Bg
*/

#include<queue>

using namespace std;
 
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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> que;
        if(root){
            que.push(root);
        }

        while(!que.empty()){
            TreeNode* tempNode = que.front();
            que.pop();
            swap(tempNode->left,tempNode->right);

            if(tempNode->left) que.push(tempNode->left);
            if(tempNode->right) que.push(tempNode->right);

        }

        return root;
    }
};