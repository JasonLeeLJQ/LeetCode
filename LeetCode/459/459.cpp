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
    bool repeatedSubstringPattern(string s) {
        if(s.size() == 0 || s.size() ==1 ) return false;
        vector<int> divide = Divisible(s.size());
        int i,j,len,num;
        bool flag = true;
        //暴力解法
        for(auto it=divide.begin(); it!=divide.end();++it){
            len = *it;
            for(i=0;i<len;++i){
                num = s.size() / len;
                for(j=0;j<num-1;++j){
                    if(s[len*j+i] != s[len*(j+1) +i]){
                        flag = false;
                        break;                        
                    }
                }
                if(!flag)
                    break;
            }
            if(flag && i == len){
                return true;
            }
            flag = true;
        }
        return false;
    }
    //获取因子，找出可以整除size的数
    vector<int> Divisible(int size){
        vector<int> v;
        if(size <= 0) return v;
        /* 找出可以整除size的数，最大因子是size/2即可 */
        for(int i=1;i<=size/2;++i){
            if( (size%i) ==0){
                v.push_back(i);
            }
        }
        return v;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string s = "abab";
        
    bool ret = Solution().repeatedSubstringPattern(s);

    string out = boolToString(ret);
    cout << out << endl;
    return 0;
}