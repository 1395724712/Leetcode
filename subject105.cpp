/**
 * Copyright@wh
 * Author:wh
 * Date:20210215
 * Description:根据前序和中序序列恢复二叉树
 * Resolution:和106一样的做法
 * https://mp.weixin.qq.com/s/7r66ap2s-shvVvlZxo59xg
*/

#include "TreeStruct.hpp"
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()){
            return NULL;
        }

        //首先确定当前的根节点
        TreeNode* root = new TreeNode(preorder[0]);

        //然后分割中序序列
        vector<int>::iterator loc = find(inorder.begin(),inorder.end(),root->val);
        vector<int> leftInorder(inorder.begin(),loc);
        vector<int> rightInorder(loc+1,inorder.end());

        //接着分割前序序列
        vector<int> leftPreorder(preorder.begin()+1,preorder.begin()+1+leftInorder.size());
        vector<int> rightPreorder(preorder.begin()+1+leftInorder.size(),preorder.end());

        //递归部分
        root->left = buildTree(leftPreorder,leftInorder);
        root->right = buildTree(rightPreorder,rightInorder);
        
        return root;
    }
};
