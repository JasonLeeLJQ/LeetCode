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
    int lengthOfLastWord(string s) {
        int lens = 0;
        bool flag = true;
        for(auto it=s.rbegin(); it != s.rend(); ++it){
            if(flag && *it == ' '){
                continue;
            }
            else if(!flag && *it == ' '){
                return lens;
            }
            else{
                flag = false;
                ++lens;
            }
        }
        return lens;
    }
};