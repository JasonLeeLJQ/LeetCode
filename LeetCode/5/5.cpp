#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        //首先找单个字符回文
        int lens = s.size();
        string str1_max;
        string str2_max;
        for(int i=0; i< lens; ++i){
            int j = i;
            int index = 1;
            while(i-index >= 0 && j+index < lens && s[i-index] == s[j+index]){
                ++index;
            }
            --index;
            string tmp(s, i-index, 2*index +1);
            if(tmp.size() > str1_max.size()){
                str1_max = tmp;
            }
        }
        //再找2个字符回文
        for(int i=0; i < lens-1; ++i){
            int j = i+1;
            int index = 0;
            while(i-index >= 0 && j+index <lens && s[i-index] == s[j+index]){
                ++index;
            }
            --index;
            string tmp(s, i-index, (j - i + 2*index +1));
            if(tmp.size() > str2_max.size()){
                str2_max = tmp;
            }
        }
        return str1_max.size() > str2_max.size()? str1_max : str2_max;
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
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}