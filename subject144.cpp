/**
 * Copyright@wh
 * Author:wh
 * Date:20210203
 * Description:前序遍历
 * Resolution:挺简单的，为啥是道中等题
 * https://mp.weixin.qq.com/s/PwVIfxDlT3kRgMASWAMGhA
*/

#include<vector>

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
    void travelsal(const TreeNode* root,vector<int> &res){
        if(root == NULL){
            return;
        }
        res.push_back(root->val);
        travelsal(root->left,res);
        travelsal(root->right,res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        travelsal(root,res);
        return res;
    }
};