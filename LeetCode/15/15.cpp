#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <assert.h>
using namespace std;

//首先排序，然后遍历一遍，每次确定一个值，就可以把问题转换成 2sum，用双指针做，时间复杂度 O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> result;
        set<vector<int>> res;
        vector<int> tmp;
        if(nums.size()<3) return result;
        sort(nums.begin(),nums.end());
        for(int first=0;first<nums.size()-2;++first){
            if(first == 0 || (first -1 >=0 && nums[first] != nums[first-1]) ){ //去除重复元素，不需要重复计算
                int target = 0 - nums[first];
                find_two_num(target, nums, first+1, res);
            }
        }
        for(auto it=res.begin();it!=res.end();++it){
            result.push_back(*it);
        }
        return result;
    }
    void find_two_num(int target, vector<int> nums, int first,set<vector<int>> &res){
        int begin=first,end=nums.size()-1;
        int number = -1 * target;
        vector<int> tmp;
        while(begin < end){
            if(nums[begin] + nums[end] < target)
                ++begin;
            else if(nums[begin] + nums[end] > target)
                --end;
            else{
                tmp.push_back(nums[begin]);
                tmp.push_back(nums[end]);
                if(number >= nums[begin] && number >= nums[end]) tmp.push_back(number);
                else if(number > nums[begin] && number < nums[end]) tmp.insert(tmp.begin()+1,number);
                else if(number <= nums[begin] && number <= nums[end]) tmp.insert(tmp.begin(),number);
                res.insert(tmp);
                ++begin;
                --end;
                tmp.clear();
            }
        }
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums;
    int n[]={0,0,0,1};
    for(int i=0;i<4;++i){
        nums.push_back(n[i]);
    }
    Solution s;
    vector<vector<int>> res = s.threeSum(nums);

    for(auto it=res.begin(); it!=res.end();++it){
        for(auto j=it->begin(); j!=it->end();++j){
            cout<<*j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
