#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
  public:
    // int solver(int i, int j, vector<vector<int>>&dp, vector<int>&nums){
    //     if(i>=j)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int ans=INT_MAX;
    //     for(int k=i;k<j;k++){
    //         int cost=solver(i,k,dp,nums)+solver(k+1,j,dp,nums)+nums[i-1]*nums[j]*nums[k];
    //         ans=min(ans,cost);
            
    //     }
    //     return dp[i][j]=ans;
        
    // }
    int matrixMultiplication(vector<int> &arr) {
        // code here
          int n=arr.size();
        if(n<=2)return 0;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int len=2;len<n;len++){
            for(int i=1;len+i-1<n;i++){
                int j=len+i-1;
                dp[i][j]=INT_MAX;
                for(int k=i;k<j;k++){
                    int cost= dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
                    dp[i][j]=min(dp[i][j], cost);
                }
            }
        }
        return dp[1][n-1];
        // int n=arr.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return solver(1,n-1,dp,arr);
    }
};