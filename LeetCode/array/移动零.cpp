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

//解法1：STL内置的分类算法
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        stable_partition(nums.begin(),nums.end(),[](int &a){if(a != 0) return true; else return false;});
    }
};

//解法二：遍历数组，把所有非零元素移动到数组开头，后面补0