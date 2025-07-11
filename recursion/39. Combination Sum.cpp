#include<vector>

using namespace std;
class Solution {
public:

    void solver(int i,vector<int>&temp,vector<int>& candidates, int target, vector<vector<int>>&ans ){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0 || i>=candidates.size())return;
        temp.push_back(candidates[i]);
        solver(i,temp,candidates,target-candidates[i],ans);
        temp.pop_back();
        solver(i+1,temp,candidates,target,ans);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>>ans;
        vector<int>temp;
        solver(0,temp,candidates,target,ans);
        return ans;
    }
};