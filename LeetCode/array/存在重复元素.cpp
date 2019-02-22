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

class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        //建立字典，map<数组元素，出现的次数>
        map<int, int> table;
        for(int i=0;i<nums.size();++i){
            if(table.find(nums[i]) != table.end()) return true;
            else table[nums[i]] = 1;
        }
        return false;
    }
};


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //先排序，再查找重复元素
        sort(nums.begin(),nums.end());
        int len=nums.size();
        for(int i=0;i<len-1;i++){
            if(nums[i]==nums[i+1]) return 1;
        }
        return 0;
    }
};