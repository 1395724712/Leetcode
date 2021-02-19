/**
 * Copyright@wh
 * Author:wh
 * Date:20210219
 * Description:删除二叉搜索树中的节点
 * Resolution:找到，然后删除，最后拼接
*/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        //终止条件
        if(root==NULL){
            return root;
        }
        if(key>root->val){
            root->right = deleteNode(root->right,key);
        }
        else if(key<root->val){
            root->left = deleteNode(root->left,key);
        }
        else{   
            //当前节点为目标节点
            if(root->left==NULL&&root->right==NULL){
                return NULL;
            }
            else if(root->left==NULL){
                return root->right;
            }
            else if(root->right==NULL){
                return root->left;
            }
            else{
                //如果目标节点左右子树均不为空
                TreeNode *target = root->right;
                while(target->left!=NULL){
                    target = target->left;
                }
                target->left = root->left;
                return root->right;
            }
        }
        return root;
    }
};