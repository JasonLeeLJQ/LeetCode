#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <set>
#include <stack>
#include <algorithm>
#include <assert.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
//双循环法
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode* tmp=head;
        while(tmp != nullptr){
            size++;
            tmp = tmp->next;
        }
        //注意边界条件，当删除的是头结点时需要特别注意
        if(n>size) return head;
        if(n == size) return head->next;
        tmp = head;
        for(int i=0;i<size-n-1;++i){
            tmp = tmp->next;
        }
        ListNode* del = tmp->next;
        tmp->next = del->next;
        delete del;
        return head;
    }
};

//添加哑节点的双循环法
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy = ListNode(0);
        dummy.next = head;
        int size=0;
        ListNode* tmp=head;
        while(tmp != nullptr){
            size++;
            tmp = tmp->next;
        }
        if(n>size) return head;
        tmp = &dummy;
        for(int i=0;i<size-n;++i){
            tmp = tmp->next;
        }
        ListNode* del = tmp->next;
        tmp->next = del->next;
        delete del;
        return dummy.next;
    }
};

//添加哑节点的单循环法
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy = ListNode(0);
        dummy.next = head;
        ListNode *tmp = &dummy;
        for(int i=0;i<n+1;++i){
            tmp = tmp->next;
        }
        ListNode *fast = tmp;
        ListNode *slow = &dummy;
        while(fast != nullptr){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode *del = slow->next;
        slow->next = slow->next->next;
        delete del;
        return dummy.next;
    }
};