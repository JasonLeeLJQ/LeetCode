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

//三指针法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode *p1=head,*p2=p1->next;
        //链表只有一个结点
        if(p2 == nullptr) return head;
        ListNode *p3=p2->next;
        //链表只有两个结点
        if(p3 == nullptr){
            p2->next = p1;
            p1->next = nullptr;
            return p2;
        }
        //链表中>=3个结点
        bool is_begin = true;
        while(p3 != nullptr){
            p2->next = p1;
            if(is_begin) {
                p1->next = nullptr;
                is_begin = false;
            }
            //易错点：p1,p2,p3赋值的顺序不能弄反
            p1 = p2;
            p2 = p3;
            p3 = p3->next;          
        }
        p2->next = p1;
        return p2;
    }
};

//双指针法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;  //链表为空直接返回，而H->next为空是递归基
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

//递归法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;  //链表为空直接返回，而H->next为空是递归基
        ListNode* newhead = reverseList(head->next);  
        head->next->next = head;  //翻转链表的指向
        head->next = nullptr;    //记得赋值NULL，防止链表错乱
        return newhead;          //新链表头永远指向的是原链表的链尾
    } 
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

void prettyPrintLinkedList(ListNode* node) {
  while (node && node->next) {
      cout << node->val << "->";
      node = node->next;
  }

  if (node) {
    cout << node->val << endl;
  } else {
    cout << "Empty LinkedList" << endl;
  }
}

int main() {
    string line="[1,2,3]";
    ListNode* head = stringToListNode(line);
    prettyPrintLinkedList(head);
    Solution s;
    head = s.reverseList(head);
    prettyPrintLinkedList(head);
    return 0;
}