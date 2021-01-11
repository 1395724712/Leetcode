/*
*Copyright@wh
*Author:wh
*Date:20210111
*Description:删除链表中等于给定值 val 的所有节点。
*Resolution:虚拟头节点 https://mp.weixin.qq.com/s/slM1CH5Ew9XzK93YOQYSjA
*/

#include<stdio.h>

/**
 * Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //虚拟头
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *cur = dummyHead;
        
        while(cur->next!=NULL)
        {
            if(cur->next->val == val){
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            }
            else{
                cur = cur->next;
            }
        }

        return dummyHead->next;
    }
};