#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    int solver(int n, vector<int>&dp, vector<int>&cost){
        if(dp[n]!=-1)return dp[n];
        return dp[n]=min(cost[n-1]+solver(n-1,dp,cost),cost[n-2]+solver(n-2,dp,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        // vector<int>dp(n+1,-1);
        // dp[0]=dp[1]=0;
        // return solver(n,dp,cost);
        int curr=0,prev1=0,prev2=0;
        for(int i=2;i<=n;i++){
            curr=min(prev1+cost[i-1],prev2+cost[i-2]);
            prev2=prev1;
            prev1=curr;
        }
        return curr;


    }
};