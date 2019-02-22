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

class Solution{
public:
    void zhuanzhijuzhen(vector<vector<int>> &nums){
        int m = nums.size();
        int n = nums[0].size();
        int result[n][m];
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(i==j){
                    result[i][i] = nums[i][i];
                }
                else{
                    result[j][i] = nums[i][j]; 
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    Solution s;
    int a[3]={1,3,5};
    int b[3]={2,4,6};
    vector<int> a1(a,a+3);
    vector<int> b1(b,b+3);
    vector<vector<int>> nums;
    nums.push_back(a1);
    nums.push_back(b1);
    s.zhuanzhijuzhen(nums);
}