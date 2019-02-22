#include <iostream>
#include <string>
#include <vector>
#include <stack>
 
using namespace std;
 
class Solution{
public:
    int function1(vector<string> &s,int n){
        vector<string> no_match;
        int sum1=0; //自身匹配的串
        int sum2=0; //组合起来匹配的串
        
        for(int i=0;i<n;++i){
            string simple("");
            if(is_match(s[i],"",simple)){
                sum1++;
            }
            else{
                no_match.push_back(simple);
            }
        }
        vector<string> a;//左括号
        vector<string> b;//右括号
        for(int i=0;i<no_match.size();++i){
            int count = 0;
            for(int j=0;j<no_match[i].size();++j){
                if(no_match[i][j] == '(')   count++;
                else count--;
            }
            if(abs(count) == no_match[i].size() ){
                if(count > 0)   a.push_back(no_match[i]);
                else b.push_back(no_match[i]);
            } 
        }

        for(int i=0;i<a.size();++i){
            for(int j=0;j<b.size();++j){
                if(a[i].size() == b[j].size())
                    sum2++;
            }
        }
        return sum1 * sum1 + sum2;
    }
    //simple：返回裁剪之后的字符串，例如“（（））））”，裁剪之后变成“））”，此时simple="))";
    bool is_match(string s1, string s2, string& simple){
        string tmp;
        if(s2.size() == 0)  tmp = s1;
        if(s1.size() != 0 && s2.size() != 0){ 
            tmp = s1+s2;
        }
       
        stack<char> stack_chara;
        for(auto it=tmp.begin();it!=tmp.end();++it){
            if(stack_chara.empty()) stack_chara.push(*it);
            else{
                char top_s = stack_chara.top();
                if(judge(top_s,*it)){
                    stack_chara.pop();
                }
                else{
                    stack_chara.push(*it);
                }
            }
        }
        if(stack_chara.empty()) {
            simple = "";
            return true;
        }
        else {
            int len = stack_chara.size();
            for(int i=0;i<len;++i){
                simple = stack_chara.top() + simple;
                stack_chara.pop();
            }
            return false;
        }
    }
    bool judge(char top,char c){
        if(top == '(' && c == ')')
            return true;
        else{
            return false;
        }
    }
};
 
int main(){
    ios::sync_with_stdio(false);
    string str;
    vector<string> s;
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>str;
        s.push_back(str);
    }
    cout<<Solution().function1(s,n)<<endl;
    return 0;
}
