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

//最基本的解法，但是时间复杂度很高
class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {
        if(k < 0) return;
        //k大于数组大小，则取模
        if(k>nums.size()) k = k % nums.size();
        for(int i=0;i<k;++i){
            move_end_to_front(nums);
        }
    }

    void move_end_to_front(vector<int>& nums){
        auto tmp = nums.begin()+ nums.size()-1;
        nums.erase(tmp);
        nums.insert(nums.begin(),*tmp);
    }
};

class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        for(int i=0;i<k;++i){
            move_end_to_front(nums);
        }
    }

    void move_end_to_front(vector<int>& nums){
        int tmp = nums[nums.size()-1];
        for(int i=nums.size()-1; i>=1; --i){
            nums[i] = nums[i-1];
        }
        nums[0]= tmp;
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k < 0) return;
        //k大于数组大小，则取模
        if(k>nums.size()) k = k % nums.size();
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
    }

    void reverse(vector<int>& nums,int begin,int end){
        int tmp;
        while(begin < end){
            tmp = nums[begin];
            nums[begin] = nums[end];
            nums[end] = tmp;
            begin++;
            end--;
        }
    }
};