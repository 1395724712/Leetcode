/**
 * Copyright@wh
 * Author:wh
 * Date:20210203
 * Description:层次遍历
 * Resolution:队列
 * https://mp.weixin.qq.com/s/Gb3BjakIKGNpup2jYtTzog
*/

#include<vector>
#include<queue>
#include<stdio.h>

using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if(root!=NULL){
            que.push(root);
        }
        while(!que.empty()){
            int len = que.size();
            vector<int> vec;
            for(int i =0;i<len;i++){
                TreeNode* tempNode = que.front();
                que.pop();
                vec.push_back(tempNode->val);
                if(tempNode->left) que.push(tempNode->left);
                if(tempNode->right) que.push(tempNode->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};