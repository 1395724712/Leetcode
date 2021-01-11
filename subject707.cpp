/*
*Copyright@wh
*Author:wh
*Date:20210111
*Description:实现对链表的增删改查
*Resolution:总体来说不难 https://mp.weixin.qq.com/s/Cf95Lc6brKL4g2j8YyF3Mg
*/

#include<stdio.h>

class MyLinkedList {
public:
    //定义链表结构
    struct LinkedNode{
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val),next(NULL){};
    };
    /** Initialize your data structure here. */
    MyLinkedList() {
        //创造一个虚拟头节点
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        //如果index无效
        if(index>=_size){
            return -1;
        }

        LinkedNode* cur = _dummyHead->next;

        while(index--){
            cur = cur->next;
        }

        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LinkedNode* tmp = new LinkedNode(val);
        tmp->next = _dummyHead->next;
        _dummyHead->next = tmp;
        _size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkedNode *cur = _dummyHead;
        while(cur->next!=NULL){
            cur = cur->next;
        }
        cur->next = new LinkedNode(val);
        _size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list.
     * If index equals to the length of linked list, the node will be appended to the end of linked list. 
     * If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>_size){
            return;
        }

        LinkedNode* cur = _dummyHead;

        while(index--){
            cur = cur->next;
        }

        LinkedNode* tmp = new LinkedNode(val);
        tmp->next = cur->next;
        cur->next = tmp;
        _size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index>=_size||index<0){
            return;
        }

        LinkedNode* cur = _dummyHead;
        while(index--){
            cur = cur->next;
        }
        
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }
private:
    int _size;
    LinkedNode* _dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */