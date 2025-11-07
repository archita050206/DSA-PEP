#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    // void solver(vector<int>&temp, vector<bool>&visited, vector<int>nums, vector<vector<int>>&ans, int n){
    //     if(temp.size()==n){
    //         ans.push_back(temp);
    //         return;
    //     }
    //     for(int i=0;i<n;i++){
    //         if(visited[i])continue;
    //         visited[i]=true;
    //         temp.push_back(nums[i]);
    //         solver(temp,visited,nums,ans,n);
    //         visited[i]=false;
    //         temp.pop_back();
    //     }
    // }

    void solver(int start,vector<int>nums, vector<vector<int>>&ans, int n){
        if(start==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=start;i<n;i++){
            swap(nums[i],nums[start]);
            solver(start+1,nums,ans,n);
            swap(nums[i],nums[start]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        // vector<int>temp;
        // vector<bool>visited(n,false);
        // solver(temp,visited,nums,ans,n);
        solver(0,nums,ans,n);
        return ans;
    }
};