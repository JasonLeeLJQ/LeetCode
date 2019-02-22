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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        ListNode* middle = find_middle(head);
        ListNode *cur = middle->next;
        ListNode *behind = reverse_link(cur);  //将链表后半部分翻转

        //比较
        ListNode *pos=head;
        while(behind != nullptr){
            if(pos->val != behind->val)
                return false;
            behind = behind->next;
            pos = pos->next;            
        }
        return true;
    }

    //快慢指针法找到链表的中点
    ListNode* find_middle(ListNode* head){
        ListNode* fast=head,*slow=head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;  //快指针走两步
            slow = slow->next;        //慢指针走一步
        }
        return slow;
    }
    //反转链表
    ListNode *reverse_link(ListNode *head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *newhead=nullptr,*p=head,*tmp;
        while(p != nullptr){
            tmp = p->next;
            p->next = newhead;
            newhead = p;
            p = tmp;
        }
        return newhead;
    }
};

//使用栈方法，将链表翻转转换成入栈出栈操作
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        stack<int> stack_value;
        ListNode* middle = find_middle(head,stack_value);

        //比较
        ListNode *pos=middle->next;
        while(pos != nullptr){
            int ano_value = stack_value.top();
            stack_value.pop();
            if(pos->val != ano_value)
                return false;
            pos = pos->next;        
        }
        return true;
    }

    //快慢指针法找到链表的中点
    ListNode* find_middle(ListNode* head, stack<int> &stack_value){
        ListNode* fast=head,*slow=head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            stack_value.push(slow->val);
            fast = fast->next->next;  //快指针走两步
            slow = slow->next;        //慢指针走一步   
        }
        return slow;
    }
};