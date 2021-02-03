/**
 * Copyright@wh
 * Author:wh
 * Date:20210203
 * Description:求每一层的平均值
 * Resolution：还是层次遍历嘛
 * https://mp.weixin.qq.com/s/c_zCrGHIVlBjUH_hJtghCg
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> que;

        if(root!=NULL){
            que.push(root);
        }

        while(!que.empty()){
            int len = que.size();
            double sum = 0;
            for(int i = 0;i<len;i++){
                TreeNode * tempNode = que.front();
                que.pop();
                sum+= tempNode->val;
                if(tempNode->left) que.push(tempNode->left);
                if(tempNode->right) que.push(tempNode->right);
            }
            res.push_back(sum/len);
        }

        return res;
    }
};