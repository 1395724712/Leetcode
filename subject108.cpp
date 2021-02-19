/**
 * Copyright@wh
 * Author:wh
 * Date:20210219
 * Description:高度平衡二叉树
 * Resolution:注意，是每个节点的左右子树相差不能超过一，还是用递归吧，简单一点
 * https://mp.weixin.qq.com/s/sy3ygnouaZVJs8lhFgl9mw
*/

#include"TreeStruct.hpp"
#include<vector>

using namespace std;

class Solution {
private:
    TreeNode* buildSearchTree(const vector<int>& nums,int left,int right){
        //终止条件
        if(right<left){
            return NULL;
        }
        int mid = (left+right)/2;

        TreeNode* cur = new TreeNode(nums[mid]);
        cur->left = buildSearchTree(nums,left,mid-1);
        cur->right = buildSearchTree(nums,mid+1,right);
        return cur;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildSearchTree(nums,0,nums.size()-1);
    }
};