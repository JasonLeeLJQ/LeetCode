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

//使用string自己的方法find_first_of方法
class Solution {
public:
    int countSegments(string s) {
        if(s.empty()) return 0;
        vector<string> child;
        string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHJKLMNOPQRSTUVWXYZ,.!?:+=-`~$%&";
        string symbol = " ";
        string::size_type location1= s.find_first_of(alphabet);
        string::size_type location2;
        if(location1 != string::npos)
            location2 = s.find_first_of(symbol,location1);
        else
            location2 = string::npos;
        while(location2 != string::npos && location1 != string::npos){
            child.push_back(s.substr(location1,location2-location1));
            location1 = s.find_first_of(alphabet,location2);
            if(location1!=string::npos){
                location2 = s.find_first_of(symbol,location1);
            }
            else
                location2 = string::npos;
        }
        if(location1 != string::npos && location2 == string::npos){
            child.push_back(s.substr(location1,s.size()-location1));
        }
        for(auto it=child.begin(); it != child.end(); ++it){
            cout<<*it<<endl;
        }
        return child.size();
    }
}; 

//双指针法
class Solution {
public:
    int countSegments(string s) {
        if(s.empty()) return 0;
        if(s.size() == 1) {if(s[0] == ' ') return 0; else return 1;};
        int pos1=0;
        int nums=0;
        bool isFirst=true;
        while(pos1<s.size() -1){
            if(s[pos1] == ' ' && s[pos1+1] != ' '){
                if(isFirst) isFirst = false;
                nums++;      
            }
            else if(s[pos1] != ' ' && isFirst){
                nums++;
                isFirst = false;
            }
            ++pos1;
        }
        return nums;
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
    string s = ", , , ,        a, eaefa";

    int ret = Solution().countSegments(s);

    string out = to_string(ret);
    cout << out << endl;
    return 0;
}