#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
bool solver(vector<int>& nums, int n, int target,  vector<vector<int>>&dp){
    if(target==0)return true;
    if(n==0)return false;
    if(dp[n][target]!=-1)return dp[n][target];
    if(nums[n-1]<=target){
        return dp[n][target]=solver(nums,n-1,target-nums[n-1],dp)||solver(nums,n-1,target,dp);
    }
    else return dp[n][target]=solver(nums,n-1,target,dp);
    return dp[n][target];
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size(), sum=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0)return false;
        int target=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        //return solver(nums,n,target,dp);
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=0;i<=target;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]]||dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][target];
    }
};