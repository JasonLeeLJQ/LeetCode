#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <assert.h>
using namespace std;

//暴力破解
/*class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i;
        string tmp, p;
        
        if(strs.size() == 0) return string("");
        if(strs.size() == 1) return strs[0];
        tmp = strs[0];
        for(int index=1;index <strs.size();++index){
            i=0;
            while(i< tmp.size() && i < strs[index].size() && tmp[i] == strs[index][i]){
                p.push_back(tmp[i]);
                ++i;  
            }
            tmp = p;
            p.clear();
        }
        return  tmp;
    }
};*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i;
        string tmp, p;
        bool flag = false;
        if(strs.size() == 0) return string("");
        if(strs.size() == 1) return strs[0];
        for(int i=0;i<strs[0].size();++i){
            for(int j=0;j<strs.size()-1;++j){
                if(i>= strs[j].size() || i>= strs[j+1].size() || strs[j][i] != strs[j+1][i]){
                    flag = true;
                    break;
                }
            }
            if(flag){
                if(i !=0 ) return string(strs[0],0,i);
                if(i == 0) return string("");
            }
        }
        return strs[0];
    }
};

int main()
{
    vector<string> strs;
    strs.push_back("a");
    strs.push_back("a");
    strs.push_back("a");
    //strs.push_back("");
    Solution s;
    cout<< s.longestCommonPrefix(strs)<<endl;
}