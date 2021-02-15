/**
 * Copyright@wh
 * Author:wh
 * Date:20210215
 * Description:构建最大二叉树
 * Resolution:还是一个递归函数
 * https://mp.weixin.qq.com/s/1iWJV6Aov23A7xCF4nV88w
*/
#include<vector>
#include"TreeStruct.hpp"

using namespace std;

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        //终止条件
        if(nums.empty()){
            return NULL;
        }

        TreeNode *root = new TreeNode(0);

        //寻找最大值
        int maxValue = -1;
        int maxValueIndex = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if(maxValue<nums[i]){
                maxValue = nums[i];
                maxValueIndex = i;
            }
        }
        root->val = maxValue;
        vector<int> leftNums(nums.begin(),nums.begin()+maxValueIndex);
        vector<int> rightNums(nums.begin()+maxValueIndex+1,nums.end());

        root->left = constructMaximumBinaryTree(leftNums);
        root->right = constructMaximumBinaryTree(rightNums);

        

        return root;
    }
};