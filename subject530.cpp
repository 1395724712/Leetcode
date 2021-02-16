/**
 * Copyright@wh
 * Author:wh
 * Date:20210216
 * Description:在二叉搜索树中寻找最小的绝对值差
 * Resolution:二叉搜索树是有序的,攻略没怎么看懂，咱们就用中序遍历恢复出有序数组的方案吧
 * https://mp.weixin.qq.com/s/Hwzml6698uP3qQCC1ctUQQ
*/
#include"TreeStruct.hpp"
#include<stdio.h>
#include<vector>
using namespace std;

class Solution {
private:
    int result = INT_MAX;
    TreeNode *pre;
    void travel(TreeNode *root){
        if(root==NULL){
            return;
        }
        travel(root->left);
        if(pre){
            int temp = root->val - pre->val;
            result = result<temp?result:temp;
        }
        pre = root;
        travel(root->right);
        return ;
    }
public:
    int getMinimumDifference(TreeNode* root) {
        travel(root);
        return result;
    }
};