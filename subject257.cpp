/**
 * Copyright@wh
 * Author:wh
 * Date:20210206
 * Description:返回二叉树的所有路径
 * Resolution:从上到下递归怎么样
*/

#include<vector>
#include<string>

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

    void getPaths(TreeNode *root,string pre,vector<string>& res){
        
        if((!root->left)&&(!root->right)){
            res.push_back(pre);
            return;
        }
        
        if(root->left){
            getPaths(root->left,pre+"->"+to_string(root->left->val),res);
        }

        if(root->right){
            getPaths(root->right,pre+"->"+to_string(root->right->val),res);
        }
        
        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root){
            return res;
        }
        string pre = to_string(root->val);

        getPaths(root,pre,res);

        return res;
    }
};