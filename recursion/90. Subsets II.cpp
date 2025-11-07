#include<vector>
#include<set>
#include<algorithm>

using namespace std;
// class Solution {
// public:

//     void solver(int i, vector<int>&temp, vector<int>& nums, set<vector<int>>&ans){
//         if(i>=nums.size()){
//             ans.insert(temp);
//             return ;
//         }
//         temp.push_back(nums[i]);
//         solver(i+1,temp,nums,ans);
//         temp.pop_back();
        
//         solver(i+1, temp,nums, ans);
   
//     }

//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         set<vector<int>>ans;
//         vector<int>temp;
//         solver(0,temp,nums,ans);
       
//         return vector<vector<int>>(ans.begin(),ans.end());
        
//     }

    class Solution {
public:
void solver(int i, vector<int>nums, vector<int>&temp,  vector<vector<int>>&ans,int n){
    ans.push_back(temp);
    for(int j=i;j<n;j++){
        if(j>i &&nums[j-1]==nums[j])continue;
        temp.push_back(nums[j]);
        solver(j+1,nums,temp,ans,n);
        temp.pop_back();

    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        solver(0,nums,temp,ans,nums.size());
        return ans;
        
    }
};
