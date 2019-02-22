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
    bool isValidSudoku(vector<vector<char>>& board) {
        int table[9] = {0};
        //1、行比较
        for(auto it=board.begin();it!=board.end();++it){
            for(auto j=it->begin();j!=it->end();++j){
                if(table[*j - '0'] > 0){
                    return false;
                }
                else{
                    table[*j -'0'] = 1;
                }
            }
        }
        //2、列比较
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[i][j] > 0){
                    return false;
                }
                else{
                    table[*j -'0'] = 1;
                }
            }
        }
    }
};