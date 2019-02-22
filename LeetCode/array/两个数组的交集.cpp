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

//解法1：针对较大的数组建立字典，然后遍历较小的数组，在字典中查找
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> *big;
        vector<int> *small;
        vector<int> result;
        map<int,int> table;
        if(nums1.size() > nums2.size()){
            big=&nums1;
            small=&nums2;
        } else {
            big=&nums2;
            small=&nums1;
        }
        //1、建立字典
        for(auto it=big->begin(); it!=big->end(); ++it){
            map<int,int>::iterator location = table.find(*it);
            if( location != table.end()){
                location->second++;
            }
            else{
                table[*it] = 1;
            }
        }
        //2、查找字典
        for(auto it=small->begin(); it!=small->end();++it){
            map<int,int>::iterator location = table.find(*it);
            if( location != table.end() && location->second > 0){
                location->second--;
                result.push_back(location->first);
            }
        }
        return result;
    }
};

//解法二：给两个数组排序，然后用两个索引分别代表两个数组的起始位置，如果两个索引所代表的数字相等，
//则将数字存入结果中，两个索引均自增1，如果第一个索引所代表的数字大，则第二个索引自增1，反之亦然。
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        //数组从小到大排序
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int p=0,q=0;
        while(p < nums1.size() && q < nums2.size()){
            if(nums1[p] == nums2[q]){
                result.push_back(nums1[p]);
                p++;
                q++;
            }
            else if(nums1[p] > nums2[q]){
                q++;
            }
            else{
                p++;
            }
        }
        return result;
    }
};