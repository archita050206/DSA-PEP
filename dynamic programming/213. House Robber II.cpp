#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    int solver(vector<int>& nums, int i, vector<int>&dp, int n){

        if(i>=n)return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        int steal=nums[i]+solver(nums,i+2,dp,n);
        int skip=solver(nums,i+1,dp,n);
        return dp[i]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)return nums[0];
        vector<int>v1,v2;
        for(int i=0;i<=(n-2);i++){
            v1.push_back(nums[i]);
        }
        for(int i=1;i<=(n-1);i++){
            v2.push_back(nums[i]);
        }
        vector<int>dp1(n-1,-1),dp2(n-1,-1);
        return max(solver(v1,0,dp1,n-1),solver(v2,0,dp2,n-1));
    }
};