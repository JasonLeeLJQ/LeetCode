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
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        unsigned int sum=0;
        unsigned int upgrade=1;
        for(auto it=digits.rbegin();it!=digits.rend();++it){
            sum = *it + upgrade;
            result.insert(result.begin(),sum%10);
            upgrade = sum / 10;
        }
        if(upgrade > 0) result.insert(result.begin(),upgrade);
        return result;
    }
};