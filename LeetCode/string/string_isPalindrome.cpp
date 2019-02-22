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

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()==0) return true;
        int p=0,q=s.size()-1;
        while(p<q){
            while(!isalnum(s[p])){
                p++;
            }
            while(!isalnum(s[q])){
                q--;
            }
            if(p<q) return true;
            //转换成小写字母
            if(tolower(s[p]) == tolower(s[q])){
                p++;
                q--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str="A bc ba";
    cout<< s.isPalindrome(str) <<endl;
    return 0;
}
