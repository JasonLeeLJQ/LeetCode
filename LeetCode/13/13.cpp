#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        for(int i=0; i<s.size(); ++i){
            switch(s[i]){
                case 'I':{
                    if(s[i+1] != 'V' && s[i+1] != 'X'){
                        sum += 1;
                    }
                    else{
                        if(s[i+1] == 'V')
                            sum += 4;
                        else if(s[i+1] == 'X')
                            sum += 9;
                        ++i;
                    }
                    break;
                }
                case 'X':{
                    if(s[i+1] != 'L' && s[i+1] != 'C'){
                        sum += 10;
                    }
                    else{
                        if(s[i+1] == 'L')
                            sum += 40;
                        else if(s[i+1] == 'C')
                            sum += 90;
                        ++i;
                    }
                    break;
                }
                case 'C':{
                    if(s[i+1] != 'D' && s[i+1] != 'M'){
                        sum += 100;
                    }
                    else{
                        if(s[i+1] == 'D')
                            sum += 400;
                        else if(s[i+1] == 'M')
                            sum += 900;
                        ++i;
                    }
                    break;
                }
                case 'V':{
                    sum += 5;
                    break;
                }
                case 'L':{
                    sum += 50;
                    break;
                }
                case 'D':{
                    sum += 500;
                    break;
                }
                case 'M':{
                    sum += 1000;
                    break;
                }
            }
            
        }
        return sum;
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
        
        int ret = Solution().romanToInt(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}