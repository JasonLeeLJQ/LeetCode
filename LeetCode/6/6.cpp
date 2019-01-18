#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        int per_num = numRows == 1 ? (numRows*2 -2) : 1;  //每个循环有几个字符，此时要判断numRow==1这个特殊情况

        for(int col=0; col < numRows; ++col){
            for(int i=0;i<s.size();++i){
                if(i % per_num == col || i % per_num == (per_num - col)){
                    result.push_back(s[i]);
                }
            }
        }
        return result;
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int numRows = stringToInteger(line);
        
        string ret = Solution().convert(s, numRows);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}