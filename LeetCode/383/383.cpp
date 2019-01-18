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


//方法：对magazine组成hashmap，key为出现的字符，value为字符的个数
//遍历ransomNote的每个字符，只要在hashmap中命中，则value--；直到找不到该字符或者找到该字符但是value==0，返回false；
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.empty() && magazine.empty()) return true;
        if(!ransomNote.empty() && magazine.empty()) return false;
        //组成hash table
        map<char,int> table;
        for(auto it=magazine.begin(); it != magazine.end(); ++it){
            if(!table.empty()){
                auto location = table.find(*it);
                if(location != table.end())
                    (location->second)++;
                else
                    table.insert(pair<char,int>(*it,1));
            }
            else
                table.insert(pair<char,int>(*it,1));
        }
        //for_each(table.begin(),table.end(),[](pair<char,int> iter){cout<<iter.first<<" "<<iter.second;});
        //cout<<endl;
        string::iterator index;
        for(index=ransomNote.begin(); index!=ransomNote.end();++index){
            auto res = table.find(*index);
            if(res != table.end() && res->second > 0){
                (res->second)--; //
            }
            else{
                return false;
            }
        }
        if(index == ransomNote.end()) return true;
        else return false;
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
    string ransomNote = "aa";
    string magazine = "aab";
        
    bool ret = Solution().canConstruct(ransomNote, magazine);

    string out = boolToString(ret);
    cout << out << endl;
    return 0;
}