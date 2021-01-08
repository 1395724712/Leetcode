/*
*Copyright:wh
*Author:wh
*Date:20210108
*Description:反转一个单链表
*Resolution:三指针
*/
#include<stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //前指针，当前指针，后指针
        ListNode* pre,*cur,*next;
        pre = head;
        if(head!=NULL)
        {
            cur = head->next;
        }
        else
        {
            cur = NULL;
            return NULL;
        }
        if(cur!=NULL){
            next = head->next->next;
        }
        else
        {
            next = NULL;
            return pre;
        }

        pre->next = NULL;
        cur->next = pre;

        while(next!=NULL){
            pre = cur;
            cur = next;
            next = cur->next;

            cur->next = pre;
        }

        return cur;
    }
};