/**
 * Copyright@wh
 * Author:wh
 * Date:20210204
 * Description:检查点云是否对称
 * Resolution:迭代法，基本思路是每次检查队列前两个节点的值是否一样，如果一样，则将该这两个节点的左右，右左节点压栈
 * https://mp.weixin.qq.com/s/Kgf0gjvlDlNDfKIH2b1Oxg
*/

#include<queue>
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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        if(root==NULL){
            return false;
        }
        //首先将根节点的左右子节点压栈
        if(root->left==NULL&&root->right==NULL){
            return true;
        }
        else if(root->left==NULL&&root->right!=NULL){
            return false;
        }
        else if(root->left!=NULL&&root->right==NULL){
            return false;
        }
        else if(root->left->val!=root->right->val){
            return false;
        }

        que.push(root->left);
        que.push(root->right);

        while(!que.empty()){
            //将前两个节点弹出
            TreeNode* tempNode1 = que.front();
            que.pop();
            TreeNode* tempNode2 = que.front();
            que.pop();

            //然后将左右，右左节点检查后压栈

            //左右
            if((tempNode1->left == NULL||tempNode2->right == NULL)&&tempNode1->left!=tempNode2->right){
                //二者之一为NULL
                return false;
            }
            else if(tempNode1->left==NULL&&tempNode2->right==NULL){
                //均为NULL,不需要任何处理
            }
            else if(tempNode1->left->val!=tempNode2->right->val){
                //值不对称
                return false;
            }
            else{
                que.push(tempNode1->left);
                que.push(tempNode2->right);
            }

            //右左
            if((tempNode1->right == NULL||tempNode2->left == NULL)&&tempNode1->right!=tempNode2->left){
                //二者之一为NULL
                return false;
            }
            else if(tempNode1->right==NULL&&tempNode2->left==NULL){
                //均为NULL,不需要任何处理
            }
            else if(tempNode1->right->val!=tempNode2->left->val){
                //值不对称
                return false;
            }
            else{
                que.push(tempNode1->right);
                que.push(tempNode2->left);
            }
        }

        return true;

    }
};