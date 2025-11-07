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

    // void solver(int i, vector<int>&temp,vector<int>&nums, vector<vector<int>>&ans, int sum,int target){
    //     if(sum==target){
    //         ans.push_back(temp);
    //         return;
    //     }
    //     if(i>=nums.size() || sum>target)return;

    //     for(int j=i;j<nums.size();j++){
    //         if(j>i && nums[j-1]==nums[j])continue;
    //         if(sum+nums[j]>target)break;
    //         temp.push_back(nums[j]);
    //         solver(j+1,temp,nums,ans,sum+nums[j],target);
    //         temp.pop_back();
    //     }
    // }
    // vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
    //     sort(nums.begin(),nums.end());
    //     vector<vector<int>>ans;
    //     vector<int>temp;
    //     solver(0,temp,nums,ans,0,target);
    //     return ans;
    // }
};