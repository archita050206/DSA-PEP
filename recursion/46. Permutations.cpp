#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    void solver(vector<int>&temp, vector<bool>&visited, vector<int>nums, vector<vector<int>>&ans, int n){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(visited[i])continue;
            visited[i]=true;
            temp.push_back(nums[i]);
            solver(temp,visited,nums,ans,n);
            visited[i]=false;
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>visited(n,false);
        solver(temp,visited,nums,ans,n);
        return ans;
    }
};