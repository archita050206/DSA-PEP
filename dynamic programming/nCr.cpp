#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    int fun(int n, int r,vector<vector<int>>&dp){
        if(r>n)return 0;
        if(r==0 || r==n) return 1;
        if(dp[n][r]!=-1)return dp[n][r];
        return dp[n][r]=fun(n-1,r-1,dp)+fun(n-1,r,dp);
    }
    int nCr(int n, int r) {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(r+1,-1));
        return fun(n,r,dp);
    }
};