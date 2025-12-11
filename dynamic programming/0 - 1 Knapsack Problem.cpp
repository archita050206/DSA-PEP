#include <vector>
#include <queue>
using namespace std;
class Solution {
  public:
  
    int solver(vector<int> &wt, vector<int> &val, int Cap, int n){
        if(Cap==0 || n==0)return 0;
        //take
        if(wt[n-1]<=Cap){
            return max(val[n-1]+solver(wt,val,Cap-wt[n-1],n-1), solver(wt,val,Cap,n-1));
        }
        else if(wt[n-1]>Cap){
            return solver(wt,val,Cap,n-1);
        }
    }
    int solver(vector<int> &wt, vector<int> &val, int Cap, int n, vector<vector<int>>&dp){
        if(Cap==0 ||n==0 )return 0;
        if(dp[n][Cap]!=-1)return dp[n][Cap];
        if(wt[n-1]<=Cap){
            return dp[n][Cap]=max(val[n-1]+solver(wt,val,Cap-wt[n-1],n-1,dp), 
            solver(wt,val,Cap,n-1,dp));
        }
        else{
            return dp[n][Cap]=solver(wt,val,Cap,n-1,dp);
        }
        return dp[n][Cap];
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        
        int n=wt.size();
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        // return solver(wt, val, W, n,dp);
        for(int i=1;i<=n;i++){
            for(int w=1;w<=W;w++){
                int skip=dp[i-1][w];
                int take=0;
                if(wt[i-1]<=w){
                    take=val[i-1]+dp[i-1][w-wt[i-1]];
                }
                dp[i][w]=max(take,skip);
            }
        }
        return dp[n][W];
    }
};