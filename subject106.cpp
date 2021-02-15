/**
 * Copyright@wh
 * Author:wh
 * Date:20210215
 * Description:根据中序遍历结果和后序遍历结果恢复二叉树
 * Resolution:
 * https://mp.weixin.qq.com/s/7r66ap2s-shvVvlZxo59xg
*/

#include<vector>
#include "TreeStruct.hpp"
#include<algorithm>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if(inorder.empty()){
            return NULL;
        }

        //后序遍历数组的最后一位便是当前二叉树的根节点
        TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
        root->val = postorder.back();

        //然后根据根节点分割中序数组
        vector<int>::iterator loc = find(inorder.begin(),inorder.end(),root->val);

        //分割中序数组
        vector<int> leftInorder(inorder.begin(),loc);
        vector<int> rightInorder(loc+1,inorder.end());

        //分割后续数组
        vector<int> leftPostorder(postorder.begin(),postorder.begin()+leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(),postorder.end()-1);

        //递归处理
        root->left = buildTree(leftInorder,leftPostorder);
        root->right = buildTree(rightInorder,rightPostorder);



        return root;
    }
};