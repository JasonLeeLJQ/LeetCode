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
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int &a,int &b) {if(a < b) return true;else return false;});
        int i;
        for(i=0; i< nums.size()-1; i+=2){
            if(nums[i] == nums[i+1])
                continue;
            else
                return nums[i];
        }
        return nums[i];
    }
};