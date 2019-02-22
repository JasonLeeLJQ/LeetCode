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

//方法一：找到股票价格的拐点
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int result=0;
        vector<int> special;
        for(auto it=prices.begin()+1; it!=prices.end()-1;++it){
            if(*it >= *(it-1) && *it >*(it+1) || *it > *(it-1) && *it >=*(it+1) \
                || *it <= *(it-1) && *it < *(it+1) || *it < *(it-1) && *it <= *(it+1)){
                special.push_back(*it);
            }
        }
        special.insert(special.begin(),prices[0]);
        special.push_back(prices[prices.size()-1]);
        for(auto it=special.begin();it!=special.end()-1;++it){
            if(*it < *(it+1)){
                result += (*(it+1) - *it);
            }
        }
        return result;
    }
};

//方法二：在降价的前一天卖掉股票
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days=prices.size();
        if(days<=1) return 0;
        //思考过后发现，只要在降价的前一天卖掉就可以了。
        int ans=0;
        int i=1,min=prices[0];
        while(i<days)
        {
            if(prices[i]>=prices[i-1])
                i++;
            else
            {
                //如果降价就卖掉
                ans+=prices[i-1] - min;
                min=prices[i];
                i++;
            }
        }
        ans+= max(0,prices[days-1]-min);
        return ans;
    }
};