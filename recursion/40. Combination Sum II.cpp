#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
    void solver(int idx, vector<int>& candidates,vector<int>&temp, int target, int n, set<vector<int>>&ans){
        if(target==0){
            ans.insert(temp);
            return;
        }
       for(int i=idx;i<n;i++){
        if(i>idx && candidates[i]==candidates[i-1])continue;
        if(candidates[i]>target)break;
        temp.push_back(candidates[i]);
        solver(i+1,candidates,temp,target-candidates[i],n,ans);
        temp.pop_back();
       }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        set<vector<int>>ans;
        vector<int> temp;

        solver(0,candidates,temp, target, n, ans);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};