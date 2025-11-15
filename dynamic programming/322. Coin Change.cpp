#include<vector>
#include<climits>
using namespace std;

// TC--> O(n*amount)--> DP
//TC--> O(coint^amount)-->recursion

class Solution {
public:
    int solver(int amount, vector<int>&coins, vector<int>&dp){
        if(amount==0)return 0;
        if(amount<0)return INT_MAX;
        if(dp[amount]!=-1)return dp[amount];
        int mini=INT_MAX;
        for(int c: coins){
            int res=solver(amount-c, coins, dp);
            if(res<INT_MAX){
                mini=min(mini,res+1);
            }
        }
        return dp[amount]=mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans=solver(amount, coins, dp);
        return ans==INT_MAX?-1:ans;
    }

};
