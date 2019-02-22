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
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//层序遍历的输入数据
TreeNode* generate_tree(vector<string> &nums){
    if(nums.empty()) return nullptr;
    if(nums[0] == "null") return nullptr;
    TreeNode *root = new TreeNode(stoi(nums[0]));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    int i=1;
    while(true){
        if(i >= nums.size()) break;
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();
        if(nums[i] != "null"){
            node->left = new TreeNode(stoi(nums[i]));
            nodeQueue.push(node->left);
        }
        ++i;
        if(i >= nums.size()) break;
        if(nums[i] != "null"){
            node->right = new TreeNode(stoi(nums[i]));
            nodeQueue.push(node->right);
        }
        ++i;
    }
    return root;
}

//前序遍历的输入数据
TreeNode* generate_tree_pre(vector<string> &nums, int &i){
    TreeNode *root = nullptr;
    if(i < nums.size() && nums[i] != "null" ){
        root = new TreeNode(stoi(nums[i]));
        root->left = generate_tree_pre(nums,++i);
        root->right = generate_tree_pre(nums,++i);
    }
    return root;
}

//前序遍历
void print_tree_pre(TreeNode *root){
    if(root == nullptr) return;
    if(root != nullptr){
        cout<<root->val<<" ";
        print_tree_pre(root->left);
        print_tree_pre(root->right);
    }
}

//中序遍历
void print_tree_in(TreeNode *root){
    if(root == nullptr) return;
    if(root != nullptr){
        print_tree_in(root->left);
        cout<<root->val<<" ";
        print_tree_in(root->right);
    }
}

//后序遍历
void print_tree_post(TreeNode *root){
    if(root == nullptr) return;
    if(root != nullptr){
        print_tree_post(root->left);
        print_tree_post(root->right);
        cout<<root->val<<" ";
    }
}

//层序遍历
void print_tree_level(TreeNode *root){
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    while(!nodeQueue.empty()){
        TreeNode* tmp = nodeQueue.front();
        nodeQueue.pop();
        cout<< tmp->val<<" ";
        if(tmp->left != nullptr){
            nodeQueue.push(tmp->left);
        }
        if(tmp->right != nullptr){
            nodeQueue.push(tmp->right);
        }
    }
    cout<<endl;
}

//查找第K层节点的个数
int FindLevel(TreeNode* root, int k){
    if(root == nullptr || k < 0){
        return 0;
    }
    if(k == 1){
        return 1;
    }
    int left = FindLevel(root->left, k-1);
    int right = FindLevel(root->right, k-1);

    return left+right;
}

//精确查找值为x的结点
TreeNode* FindValue(TreeNode* root, int val){
    if(root == nullptr) return nullptr;
    TreeNode* ret=nullptr;
    if(root->val == val){
        ret = root;
    }
    else{
        ret = FindValue(root->left, val);
        if(ret == nullptr){
            ret = FindValue(root->right, val);
        }
    }
    return ret;
}

//查找结点总个数
int TotalNum(TreeNode* root){
    if(root == nullptr) return 0;
    int total_size = 0;
    total_size += 1;

    total_size += TotalNum(root->left);
    total_size += TotalNum(root->right);

    return total_size;
}

//计算树的深度
int DepthTree(TreeNode* root){
    if(root == nullptr) return 0;
    int depth = 0;
    depth++;
    int left = DepthTree(root->left);
    int right = DepthTree(root->right);
    depth += max(left, right);

    return depth;
}

//另一种方法计算树的深度
int DoSomething(TreeNode* ptr)
{
    int value = 0;
    if (ptr != NULL)
    {
      if (ptr -> left != NULL)
        value = 1 + DoSomething(ptr->left);
      if (ptr -> right != NULL)
        value = max(value, 1 + DoSomething(ptr->right));
    }
    return (value);
}

int main(){
    vector<string> nums;
    string str[]={"1","2","3","4","5","6"};
    int i=0;
    while(i < 6){
        nums.push_back(str[i]);
        ++i;
    }
    TreeNode* root =  generate_tree(nums);
    print_tree_pre(root);
    cout<<endl;
    print_tree_in(root);
    cout<<endl;
    print_tree_post(root);
    cout<<endl;
    print_tree_level(root);

    cout<<"第2层节点的个数:  "<<FindLevel(root, 3)<<endl;

    TreeNode* tmp =  FindValue(root, 3);
    cout<<"val=3:::   "<<tmp->val<<endl;

    cout<<"结点的总个数：  "<<TotalNum(root)<<endl;

    cout<<"maxdepth = : "<<DepthTree(root)<<endl;
    return 0;
}