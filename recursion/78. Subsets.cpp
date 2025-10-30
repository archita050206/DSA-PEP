#include<vector>
#include<string>

using namespace std;


//tc-> 2^n
// sc-> O(2^n) -> for vector
// sc-> O(n) -> for recursion(levels)
// start from i=1 to i=n, include an element, exclude another element, get sum

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

        // using bitwise operator
        // vector<vector<int>>ans;
        // int n=nums.size();
        // for(long long i=0;i<(1LL<<n);i++){
        //     vector<int>temp;
        //     for(int j=0;j<n;j++){
        //         if((i>>j)&1)temp.push_back(nums[j]);
        //     }
        //     ans.push_back(temp);
        // }
        // return ans;

    }
};