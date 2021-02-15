/**
 * Copyright@wh
 * Author:wh
 * Date:20210206
 * Description:负责输出初始化后的二叉树，并遍历检查。
 * 这是为了应对leetcode中树一类题目专门准备用来初始化输入树的
 * 输入的格式为:"1,2,3,4,null,4,5,null"
 * 
*/

#include<queue>
#include<string>
#include<vector>
#include<stdio.h>
#include<iostream>
#include"TreeStruct.hpp"
using namespace std;



//首先将输入分割
vector<string> initInput(const string& inputStr){
    vector<string> res;

    //以‘，’为分割依据
    vector<char> str;

    for(auto elem:inputStr){
        if(elem == ','){
            res.push_back(string(str.begin(),str.end()));
            str = {};
            continue;
        }
        str.push_back(elem);
    }

    res.push_back(string(str.begin(),str.end()));

    return res;
}

TreeNode* initTree(const string& inputStr){
    
    //获得初始化的节点信息
    vector<string> input = initInput(inputStr);
    if(input.empty()){
        return NULL;
    }
    
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    queue<TreeNode**> treeNode;

    treeNode.push(&root);

    for(auto elem:input){
        TreeNode** tempNode = treeNode.front();
        treeNode.pop();

        if(elem == "null"){
            delete(*tempNode);
            *tempNode = NULL;
            continue;
        }

        (*tempNode)->val = stoi(elem);

        (*tempNode)->left = (TreeNode*)malloc(sizeof(TreeNode));
        (*tempNode)->right = (TreeNode*)malloc(sizeof(TreeNode));

        treeNode.push(&(*tempNode)->left);
        treeNode.push(&(*tempNode)->right);
    }
    
    int len = treeNode.size();
    for(int i=0;i<len;i++){
        TreeNode** tempNode = treeNode.front();
        treeNode.pop();
        delete(*tempNode);
        *tempNode = NULL;
    }

    return root;
}

//然后是层次遍历吧
void treeCheck(TreeNode *root){
    if(!root){
        return;
    }
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        size_t len = que.size();
        for(int i =0;i<len;i++){
            TreeNode *tempNode = que.front();
            que.pop();
            cout<<tempNode->val<<" ";
            if(tempNode->left) que.push(tempNode->left);
            if(tempNode->right) que.push(tempNode->right);
        }
        cout<<endl;
    }
}