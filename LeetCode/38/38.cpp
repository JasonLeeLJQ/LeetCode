#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n<0 || n >30) return string("");
        string s;
        for(int i=1;i<=n;++i){
            if( i == 1){  //只有n==1是特殊的
                s = string("1");
            }
            else{
                s = generate_next_num(s); //其余的报数序列都是根据上一个数字的报数序列的结果生成的
                cout<<s<<endl;
            }
        }
        return s;
    }
    //生成某一个数的报数序列
    string generate_next_num(string s){
        int k=1;
        int i=0;
        string result;

        while(i<s.size()-1){
            if(s[i] == s[i+1]){
                ++k;
                ++i;
            }
            else{
                add_to_string(result, k, s[i]);
                k = 1;
                ++i;
            }
        }
        add_to_string(result, k, s[i]);
        return result;
    }
    //将统计的报数序列加入result字符串
    void add_to_string(string& result,int k,char c){
        result = result + to_string(k);
        result.push_back(c);
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    int n=4;
    string ret = Solution().countAndSay(n);

    string out = (ret);
    cout << out << endl;
    return 0;
}