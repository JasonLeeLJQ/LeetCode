#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <algorithm>
#include <assert.h>
using namespace std;

/* //第一次解法：使用栈
class Solution {
public:
    bool isValid(string s) {
        if(s.size()==0) return true;
        string str("{}[]()");

        stack<char> str_stack;
        for(int i=0; i<s.size();++i){
            auto index = str.find(s[i]);
            if(index != str.npos){
                if(!str_stack.empty()){
                    if(index!=0 && str_stack.top() == str[index-1]){
                        str_stack.pop();
                    }
                    else
                        str_stack.push(s[i]);
                }
                else{
                    if(index % 2 == 0)
                        str_stack.push(s[i]);
                    else
                        return false;
                }
            }
            else
                return false;
        }
        if(str_stack.empty()) 
            return true;
        else 
            return false;
    }
}; */

//第二次解法：同样使用栈，判断左括号，则入栈，右括号则比较栈顶元素
class Solution {
public:
    bool isValid(string s) {
        if(s.size()==0) return true;
        string str("{}[]()");
        
        stack<char> str_stack;
        for(int i=0; i<s.size();++i){
            auto index = str.find(s[i]);
            if(index != str.npos){
                if(index % 2 == 0){ //左括号，入栈
                    str_stack.push(s[i]);
                }
                else{
                    //注意栈此时应该不为空
                    if(!str_stack.empty() && str_stack.top() == str[index-1]) //右括号则比较栈顶元素
                        str_stack.pop();
                    else
                        return false;
                }
            }
            else
                return false;
        }
        return str_stack.empty();
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
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        bool ret = Solution().isValid(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}