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

//一般方法：find和rfind查找，如果查找到的位置相同，则说明该字符唯一
class Solution {
public:
    int firstUniqChar(string s) {
        if(s.empty()) return -1;
        string::size_type position_front, position_behind;
        int i=0;
        while(i<s.size()-1){
            if(s[i] == s[i+1]){
                i += 2;
            }
            else{
                position_front = s.find(s[i]);
                position_behind = s.rfind(s[i]);
                if(position_front == i && position_behind == i){
                    return i;
                }
                else 
                    ++i;
            }
        }
        if(i==s.size()-1){
            position_front = s.find(s[i]);
            position_behind = s.rfind(s[i]);
            if(position_front == i && position_behind == i){
                return i;
            }
            else 
                return -1;
        }
        else
            return -1;
    }
};

//hashmap方法,这个方法在构造map的时候很耗时，但是在查找的时候很快；整体运行时间还不如上面那种解法
class Solution {
public:
    int firstUniqChar(string s) {
        if(s.empty()) return -1;
        //map<字符, pair<第一次出现的位置,出现的次数>>
        map<char, pair<int,int> > hashmap;
        int index = 0;

        //构造map
        for(auto it=s.begin(); it != s.end();++it,++index){
            auto location = hashmap.find(*it);
            if(location != hashmap.end()){
                (location->second).second++;
                cout<<location->first <<": " <<location->second.first<<": "<<location->second.second<<endl;
            }
            else{
                hashmap.insert(pair<char,pair<int,int>>(*it,pair<int,int>(index,1)));
                cout<<*it <<": " <<index<<": "<<"1"<<endl;
            }
        }
        int min_index=s.size();
        for(auto iter=hashmap.begin();iter!=hashmap.end();++iter){
            if(iter->second.second == 1 && iter->second.first < min_index){
                min_index = iter->second.first;
            }
        }
        if(min_index == s.size()) return -1;
        else return min_index;
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
    string s = "cc";
        
    int ret = Solution().firstUniqChar(s);

    string out = to_string(ret);
    cout << out << endl;
    return 0;
}