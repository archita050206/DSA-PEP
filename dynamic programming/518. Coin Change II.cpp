#include<vector>
using namespace std;
class Solution {
public:
    int solver(int i, int amt, vector<int>&coins, vector<vector<int>>&dp){
        if(i>=coins.size())return 0;
        if(amt==0)return 1;
        if(dp[i][amt]!=-1)return dp[i][amt];
        // if(amt<0)return 0;
        int cnt=0;
        if(amt-coins[i]>=0){
            cnt+=solver(i,amt-coins[i],coins,dp);//--> take
        }
        cnt+=solver(i+1,amt,coins,dp);//--> not take
        return dp[i][amt]=cnt;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(amount+1,vector<int>(amount+1,-1));
        return solver(0,amount,coins,dp);
    }
};