#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <set>
#include <stack>
#include <algorithm>
#include <assert.h>
#include <sstream>
#include <queue>
#include <math.h> 
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//递归
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        
        long min = -1 *pow(2,63);
        long max = pow(2,62)-1;
        return vaild(root,min,max);
    }
    bool vaild(TreeNode* node, long min, long max){
        if(node == nullptr) return true;
        if(node->val <= min || node->val >= max) return false;
        return vaild(node->left, min, node->val) && vaild(node->right, node->val, max);
    }
};

//先中序，再判断是否是升序排列
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        vector<int> nums;
        inorder(root,nums);
        for(int i=0;i<nums.size()-1;++i){
            if(nums[i] >= nums[i+1])
                return false;
        }
        return true;
    }
    void inorder(TreeNode* root, vector<int>& nums){
        if(root == nullptr) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
};