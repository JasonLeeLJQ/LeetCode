#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <assert.h>
#include <math.h>
using namespace std;

/* 暴力破解法 */
/*class Solution {
public:
    int maxArea(vector<int>& height) {
        int tmp_area=0;
        int max_area = 0;
        for(int i=0; i< height.size()-1; ++i){
            for(int j=i+1; j < height.size();++j){
                tmp_area = (j-i) * min(height[j] , height[i]);
                if(tmp_area > tmp_area){
                    max_area = tmp_area;
                }
            }
        }
        return max_area;
    }
};*/

/* 双指针法 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int tmp_area=0;
        int max_area = 0;
        int begin = 0,end = height.size()-1;
        while(begin < end){
            tmp_area = (end-begin) * min(height[begin], height[end]);
            max_area = tmp_area>max_area ? tmp_area : max_area;
            if(height[begin] >= height[end])
                --end;
            else
                ++begin;
        }
        return max_area;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> height = stringToIntegerVector(line);
        
        int ret = Solution().maxArea(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}