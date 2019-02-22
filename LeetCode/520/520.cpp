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
    bool detectCapitalUse(string word) {
        if(word.empty()) return true;
        if(word.size() == 1) return true;
        bool upper_chara=true;
        if(isupper(word[0]) && isupper(word[1])){
            upper_chara = true;
        }
        else{
            upper_chara = false;
        }
        for(int i=2;i<word.size();++i){
            if(isupper(word[i]) != upper_chara){
                return false;
            }
        }
        return true;
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
    string word = "USA";
        
    bool ret = Solution().detectCapitalUse(word);

    string out = boolToString(ret);
    cout << out << endl;
    return 0;
}