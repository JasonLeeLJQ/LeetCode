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

//解决思路：前提条件是两字符串长度相等；遍历字符串t，针对每一个字符在字符串s中查找，查找到则从字符串S中删除，未找到则返回false；
//太耗时
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        for(auto it=t.begin(); it!=t.end();++it){
            string::size_type pos = s.find(*it);
            if(pos != string::npos){
                s.erase(s.begin()+pos);
            }
            else{
                return false;
            }
        }
        return true;
    }
};

//解法二
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int table1[26]={0};
        int table2[26]={0};
        for(int i=0; i<s.length(); ++i){
            table1[s[i]-'a']++;
            table2[t[i]-'a']++;
        }
        for(int i=0;i<26;++i){
            if(table1[i] != table2[i]){
                return false;
            }
        }
        return true;
    }
};