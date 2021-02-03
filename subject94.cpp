
/**
 * Copyright@wh
 * Author:wh
 * Date:20210203
 * Description:中续遍历
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
        travelsal(root->left,res);
        res.push_back(root->val);
        travelsal(root->right,res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        travelsal(root,res);
        return res;
    }
};