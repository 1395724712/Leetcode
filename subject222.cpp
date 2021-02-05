/**
 * Copyright@wh
 * Author:wh
 * Date:20210205
 * Description:二叉树节点数量
 * Resolution:迭代吧，层次遍历
 * https://mp.weixin.qq.com/s/2_eAjzw-D0va9y4RJgSmXw
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
    int countNodes(TreeNode* root) {
        queue<TreeNode*> que;
        if(!root){
            return 0;
        }
        int count = 0;
        que.push(root);
        while(!que.empty()){
            TreeNode* tempNode = que.front();
            que.pop();
            count++;
            if(tempNode->left) que.push(tempNode->left);
            if(tempNode->right) que.push(tempNode->right);
        }
        return count;
    }
};