#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <algorithm>
#include <assert.h>
using namespace std;
//暴力解法
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(haystack.empty()) return -1;
        int p=0,q=0;
        while(p < haystack.size()){
            if(haystack[p] == needle[q]){
                p++;
                q++;
            }
            else{
                p=p-q+1; //从下一个字符开始查找
                q=0;
            }
            if(q >= needle.size())
                return p-q;
        }
        return -1;
    }
};

//投机取巧的解法
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(haystack.empty()) return -1;
        auto index = haystack.find(needle);
        if(index != haystack.npos){
            return index;
        }
        else
            return -1;
    }
};

//效率更高的解法：KMP算法