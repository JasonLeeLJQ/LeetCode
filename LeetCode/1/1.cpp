#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int,int> hashmap;
        int index=0,new_target = 0;
        for(auto it=nums.begin(); it != nums.end(); ++it,++index){
            new_target = target - (*it);
            auto iter_result = hashmap.find(new_target);
            if(iter_result != hashmap.end() && iter_result->second != index){
                result.push_back(iter_result->second);
                result.push_back(index);
                return result;
            }
            hashmap.insert(pair<int,int>(*it,index));
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v;
    vector<int> result;
    int target = 13;
    v.push_back(2);
    v.push_back(7); 
    v.push_back(11);
    v.push_back(15);
    class Solution s;
    result = s.twoSum(v,target);

    for(auto it=result.begin(); it != result.end();++it){
        cout<<*it<<endl;
    }
    return 0;
}
