#include<vector>
#include<set>
using namespace std;
class Solution {
public:

    void solver(int idx, vector<int>& nums, vector<int>&temp,set<vector<int>>&ans, int k){
        if(k>=2){
            ans.insert(temp);
            
        }
        for(int i=idx;i<nums.size();i++){
            if(temp.empty() || temp.back()<=nums[i]){
                temp.push_back(nums[i]);
                solver(i+1,nums,temp,ans,k+1);
                temp.pop_back();
            }

        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>temp;
        solver(0,nums,temp,ans,0);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};