/**
 * Copyright@wh
 * Author:wh
 * Date:20210217
 * Description:寻找二叉搜索树的众数
 * Resolution:中序遍历，边遍历，边统计
 * https://mp.weixin.qq.com/s/KSAr6OVQIMC-uZ8MEAnGHg
*/

#include"TreeStruct.hpp"
#include<vector>
using namespace std;

class Solution {
private:
    size_t count = 0;
    size_t maxCount = 0;
    TreeNode *pre = NULL;
    vector<int> res;

    void travelCount(TreeNode *root){
        //终止条件
        if(root==NULL){
            return;
        }
        //中序遍历
        //左
        travelCount(root->left);
        //中
        if(pre==NULL){
            count = 1;
        }
        else if(pre->val == root->val){
            count++;
        }
        else{
            count = 1;
        }

        pre = root;

        if(count==maxCount){
            res.push_back(root->val);
        }
        else if(count>maxCount){
            maxCount = count; 
            res.clear();
            res.push_back(root->val);
        }

        //右
        travelCount(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        travelCount(root);
        return res;
    }
};