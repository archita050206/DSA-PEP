#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
void solver(int i, vector<int>&temp, vector<bool>&used, vector<vector<int>>&ans,vector<int>&nums){
    if(i==nums.size()){
        ans.push_back(temp);
        return;
    }
    for(int j=0;j<nums.size();j++){
        if(used[j])continue;
        if(j>0 && nums[j]==nums[j-1] &&!used[j-1])continue;//If this number is the same as the previous one,
                                                // and the previous duplicate hasn’t been used yet,
                                                // then skip the current one.
        used[j]=true;
        temp.push_back(nums[j]);
        solver(i+1,temp,used,ans,nums);
        temp.pop_back();
        used[j]=false;
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        vector<bool>used(nums.size(),false);
        solver(0,temp,used,ans,nums);
        return ans;
    }
};