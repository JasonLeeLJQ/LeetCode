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


/*
    思路：双指针法，遍历vector数组；压缩后的字符写入新的string中，最后遍历string将字符逐个拷贝到数组中。
*/
class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() == 0) return 0;
        if(chars.size() == 1) return 1;
        vector<pair<char,int>> result;
        int p=0;
        int q=p+1;
        int nums=1;
        while(q<chars.size()){
            if(chars[p] == chars[q]){
                ++nums;
            }
            else{
                result.push_back(pair<char,int>(chars[p], nums));
                nums = 1;
            }
            ++p;
            q=p+1;
        }
        result.push_back(pair<char,int>(chars[p], nums));
        string res;
        for(auto it=result.begin(); it!=result.end();++it){
            if(it->second == 1){
                res = res + it->first;
            }
            else{
                res = res + it->first + to_string(it->second);
            }
        }
        chars.clear();
        for(auto iter=res.begin(); iter!=res.end();++iter){
            chars.push_back(*iter);
        }
        return res.size();
    }
}; 

/*
    思路：双指针法，空间复杂度为O（1）；
    压缩后的结果直接写入源数组；
*/
class Solution {
public:
    int compress(vector<char>& chars) { 
        if(chars.size() == 0) return 0;
        if(chars.size() == 1) return 1;
        //vector<pair<char,int>> result;
        int p=0;
        int q=p+1;
        int nums=1;
        int pos = 0;
        while(q < chars.size()){ //双指针，一个在前，一个在后，判断是否相等
            if(chars[p] == chars[q]){
                ++nums;
            }
            else{
                if(nums == 1){
                    chars[pos++] = chars[p];
                }
                else{
                    chars[pos++] = chars[p];
                    for(int i=0;i<to_string(nums).size();++i){   //注意要将int型转成string类型
                        chars[pos++] = to_string(nums)[i];
                    }              
                }
                nums = 1;
            }
            ++p;
            q=p+1;
        }
        if(nums == 1){
            chars[pos++] = chars[p];
        }
        else{
            chars[pos++] = chars[p];
            for(int i=0;i<to_string(nums).size();++i){
                chars[pos++] = to_string(nums)[i];
            }              
        }
        /* 删除原数组中的多余元素 */
        auto it=chars.begin()+pos;
        while(it!=chars.end()){
            it = chars.erase(it);
        }
        return chars.size();
    }
};

int main(){
    vector<char> chars;
    chars.push_back('a');
    chars.push_back('a');
    chars.push_back('b');
    chars.push_back('b');
    chars.push_back('c');
    chars.push_back('c');
    chars.push_back('c');

    Solution s;
    cout<<s.compress(chars)<<endl;
}