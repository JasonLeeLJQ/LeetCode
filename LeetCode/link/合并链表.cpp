#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <set>
#include <stack>
#include <algorithm>
#include <assert.h>
#include <sstream>
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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode *p1=l1,*p2=l2;
        ListNode *newhead=nullptr,*tmp;
        if(p1->val <= p2->val){
            newhead = p1;
            p1 = p1->next;
        }
        else{
            newhead = p2;
            p2 = p2->next;
        }
        ListNode *cur = newhead;
        while(p1!=nullptr && p2!=nullptr){
            if(p1->val <= p2->val){
                cur->next = p1;
                p1 = p1->next;
            }
            else{
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        if(p1 == nullptr){
            cur->next = p2;
        }
        if(p2 == nullptr){
            cur->next = p1;
        }
        return newhead;
    }
};

//带哑结点的解法
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode dummy = ListNode(0);
        ListNode *cur = &dummy;

        ListNode *p1=l1,*p2=l2;      
        while(p1!=nullptr && p2!=nullptr){
            if(p1->val <= p2->val){
                cur->next = p1;
                p1 = p1->next;
            }
            else{
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        if(p1 == nullptr){
            cur->next = p2;
        }
        if(p2 == nullptr){
            cur->next = p1;
        }
        return dummy.next;
    }
};