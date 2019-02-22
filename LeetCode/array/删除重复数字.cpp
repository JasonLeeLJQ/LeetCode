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
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;
        auto p=nums.begin(),q=p+1;
        while(q != nums.end()){
            if(*p == *q){
                nums.erase(q);
            }
            else{
                p++;
                q++;
            }
        }
        return nums.size();
    }
};