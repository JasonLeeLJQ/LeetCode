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
    string addBinary(string a, string b) {
        int upgrade=0;
        int sum = 0;
        int p=a.size()-1,q=b.size()-1;
        string result;
        if(a.empty() || b.empty()){
            if(a.empty() && !b.empty()) return b;
            else if(!a.empty() && b.empty()) return a;
            else return string("");
        }
        int left = a[p]-48,right=b[q]-48;
        while(p >= 0 || q >= 0){
            sum += left+right +upgrade;
            upgrade = sum / 2;
            result = to_string(sum%2) + result;
            cout<<result<<endl;
            --p;
            --q;
            sum = 0;
            if(p < 0 && q >= 0){
                left = 0;
                right = b[q]-48;
            }
            else if(q < 0 && p >= 0){
                right = 0;
                left = a[p]-48;
            }
            else{
                left = a[p]-48;
                right = b[q]-48;
            }
        }
        if(upgrade) result = to_string(upgrade) + result;
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

int main() {  
    string a = "1010";
    string b = "1011";
    string ret = Solution().addBinary(a, b);

    string out = (ret);
    cout << out << endl;
    return 0;
}