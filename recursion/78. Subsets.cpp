#include<vector>
#include<string>

using namespace std;
class Solution {
public:

    void solve(int i, vector<int>&temp,  vector<int>& nums,  vector<vector<int>>&v){
        if(i>=nums.size()){
            v.push_back(temp
            );
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1, temp, nums,v);
    temp.pop_back();
    solve(i+1,temp,nums,v);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>v;
        solve(0,temp,nums,v);
        return v;

    }
};