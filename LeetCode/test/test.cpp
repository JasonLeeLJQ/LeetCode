#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

class Solution{
public:
    bool Find(int target, vector<vector<int> > array){
        int index = 0;
        int n = array.size(); //矩阵的宽m
        int m = array[0].size(); //矩阵的长n
        int flag = 0;
        int middle = middle_value(array, min(m,n), target, flag);
        if(middle == -1){
            if(flag == 1)
                return false;
            else if(flag == 3)
                return true;
            else if(flag == 4){
                int index = min(m,n)-1;
                for(int i = index;i<n;++i){
                    for(int j=index; j<m; ++j){
                        if(i != j && array[i][j] == target){
                            cout<<"location: "<< i+1 <<" "<<j+1<<endl;
                            return true;
                        }
                    }
                }
            }
        }

        for(int i = 0;i < middle;++i){
            for(int j = 0;j < m;++j ){
                if(array[i][j] == target){
                    cout<<"location: "<< i+1 <<" "<<j+1<<endl;
                    return true;
                }
                else if(array[i][j] > target){
                    break;
                }
            }            
        }

        for(int i=n-middle+1; i < n; ++i){
            for(int j=0; j < middle; ++j ){
                if(array[i][j] == target){
                    cout<<"location: "<< i+1 <<" "<<j+1<<endl;
                    return true;
                }
                else if(array[i][j] > target){
                    break;
                }
            }            
        }
        return false;
    }
    int middle_value(vector<vector<int> > array, int len, int target,int &flag){
        if(array[0][0] > target ){
            flag = 1;
            return -1;
        }
        if(array[len-1][len-1] < target){
            flag = 4;
            return -1;
        }
        for(int i=0; i<len-1; ++i){
            if(array[i][i] < target && array[i+1][i+1] > target){
                flag = 2;
                return i+1;
            }
            if(array[i][i] == target || array[i+1][i+1] == target){
                if(array[i][i] == target)
                    cout<<"location: "<< i+1 <<" "<<i+1<<endl;
                else
                    cout<<"location: "<< i+2 <<" "<<i+2<<endl;
                flag = 3;
                return -1;
            }
        }
    }
};

int main1(void) {
	/* vector<vector<int> > array(3);
	for (int i = 0; i<array.size(); i++)
	{
		array[i]
	}

	array[0].push_back(1);
	array[0].push_back(2);
	array[0].push_back(3);
	array[0].push_back(4);
	array[1].push_back(3);
	array[1].push_back(4);
	array[1].push_back(5);
	array[1].push_back(10);
	array[2].push_back(6);
	array[2].push_back(7);
	array[2].push_back(9);
	array[2].push_back(15);


	Solution s;
	cout << s.Find(10, array) << endl; */
    vector<pair<char ,int>> v;
    v.push_back(pair<char,int>('a',1));
    v.push_back(pair<char,int>('b',1));
    v.push_back(pair<char,int>('c',1));

    /* for(auto it=v.begin();it!=v.end();++it){
        cout<<it->first<<" "<<it->second<<endl;
    } */

    char c='a';
    string p= "123";
    string s = p+c;
    cout<<s<<endl;
}

int main(){
	vector<int> numbers{22, 7, 93, 45, 19, 56, 88, 12, 8, 7, 15, 10};
	int k=3;
    //partial_sort(numbers.begin(),numbers.begin()+k,numbers.end());
	//partial_sort(numbers.begin(),numbers.begin()+k,numbers.end(),[](int &a,int &b){if(a>b) return true;else return false;});
    //nth_element(numbers.begin(),numbers.begin()+k+1,numbers.end());
    nth_element(numbers.begin(),numbers.begin()+numbers.size()-1,numbers.end(),[](int &a, int &b){if(a>b) return true;else return false;});

	for(int i=0;i<numbers.size();++i){
		cout<<numbers[i]<<" ";
	}
	cout<<endl;
	return 0;
}