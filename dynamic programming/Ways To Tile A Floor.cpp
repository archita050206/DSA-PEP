#include<vector>
using namespace std;
class Solution {
  public:
    int fun(int n, vector<int>&dp){
        if(n==1 ||n==2)return n;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=fun(n-1,dp)+fun(n-2,dp);
    }
    int numberOfWays(int n) {
        // code here
        // if(n==1 || n==2)return n;
        // return numberOfWays(n-1)+numberOfWays(n-2);
        vector<int>dp(n+1,-1);
        // return fun(n,dp);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
        
    }
};