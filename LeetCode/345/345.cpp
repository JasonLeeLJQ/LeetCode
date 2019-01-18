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
    string reverseVowels(string s) {
        if(s.empty()) return string("");
        if(s.size() == 1) return s;
        
        int p=0,q=s.size()-1;
        char tmp;
        while(p<q){
            if(isVowels(s[p]) && isVowels(s[q])){
                tmp = s[p];
                s[p]=s[q];
                s[q]=tmp;
                p++;
                q--;
            }
            if(!isVowels(s[p])) p++;
            if(!isVowels(s[q])) q--;          
        }
        return s;
    }
    bool isVowels(char c){
        string table="aeiouAEIOU";  //不要忘记大写的元音字母
        auto index = table.find(c);
        if(index != table.npos){
            return true;
        }
        else
            return false;
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

int main() {
    
    string s = "hello";
    string ret = Solution().reverseVowels(s);

    string out = (ret);
    cout << out << endl;
    return 0;
}