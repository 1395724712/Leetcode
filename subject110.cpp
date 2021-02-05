/**
 * Copyright@wh
 * Author:wh
 * Date:20210204
 * Description:检查二叉树是否为平衡二叉树
 * Resolution:递归更简单一些吧，统计左右子树的高度，并比较，如果左右子树相差超过1就返回false;
*/

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
    bool calculateDep(TreeNode* root,int& depth){
        if(!root){
            depth = 0;
            return true;
        }

        int depthL = 0;
        int depthR = 0;

        int flagL = calculateDep(root->left,depthL);
        int flagR = calculateDep(root->right,depthR);

        depth = depthL>depthR?depthL+1:depthR+1;


        if(depthL>depthR+1||depthL<depthR-1){
            return false;
        }

        return flagL&&flagR;        
    }
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        int depL = 0;
        int depR = 0;
        bool flagL = calculateDep(root->left,depL);
        bool flagR = calculateDep(root->right,depR);
        if(depL>depR+1||depL<depR-1){
            return false;
        }

        return flagL&&flagR;
    }
};