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
    void rotate(vector<vector<int>>& matrix) {
        //如何旋转90°？先按照x轴对称翻转，然后沿着对角线翻转即可
        int n=matrix.size();
        for(int i=0;i<n/2;++i){
            swap(matrix[i],matrix[n-i-1]);
        }
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(i!=j){
                    swap(matrix[i][j],matrix[j][i]);
                }
            } 
        }
    }
};