#include<vector>
#include<set>
#include<algorithm>

using namespace std;
class Solution {
public:

    void solver(int i, vector<int>&temp, vector<int>& nums, set<vector<int>>&ans){
        if(i>=nums.size()){
            ans.insert(temp);
            return ;
        }
        temp.push_back(nums[i]);
        solver(i+1,temp,nums,ans);
        temp.pop_back();
        
        solver(i+1, temp,nums, ans);
   
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>>ans;
        vector<int>temp;
        solver(0,temp,nums,ans);
       
        return vector<vector<int>>(ans.begin(),ans.end());
        
    }
};