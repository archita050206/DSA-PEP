#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n=expression.length();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(expression[i]=='+'||expression[i]=='-'||expression[i]=='*'){
                string left=expression.substr(0,i);
                string right=expression.substr(i+1);
                vector<int>v1=diffWaysToCompute(left);
                vector<int>v2=diffWaysToCompute(right);
                for(int j:v1){
                    for(int k:v2){
                        if(expression[i]=='+')ans.push_back(j+k);
                        else if(expression[i]=='-')ans.push_back(j-k);
                        else if(expression[i]=='*')ans.push_back(j*k);
                    }
                }
            }
        }
        if(ans.empty())ans.push_back(stoi(expression));
        return ans;
    }
};