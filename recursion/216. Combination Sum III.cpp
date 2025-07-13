#include<vector>
using namespace std;
class Solution {
public:
    void solver(int idx, vector<int>&temp,vector<vector<int>>&ans, int k, int n){
        if(k==0 && n==0){
            ans.push_back(temp);
            return;

        }
        if(k==0 || n<0)return;
        for(int i=idx;i<=9;i++){
           temp.push_back(i);
           solver(i+1,temp,ans,k-1,n-i);
            temp.pop_back();

            
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>nums;
        
        solver(1,temp,ans,k,n);
        return ans;
    }
};