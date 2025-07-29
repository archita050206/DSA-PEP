#include<vector>

using namespace std;
class Solution {
  public:
  
    int solver(int i, vector<int>& arr, int target, int n){
        if(i==n){
            if(target==0)return 1;
            else return 0;
        }
        return solver(i+1, arr, target-arr[i], n)+solver( i+1,arr, target,n);
    }
    int solver(vector<int>& arr, int target, vector<vector<int>>&dp, int n){
      
      if(n==0)
     {
         if(target==0)return 1;
         return 0;
     }
      
      if(dp[n][target]!=-1)return dp[n][target];
      if(arr[n-1]<=target){
          dp[n][target]=solver(arr, target-arr[n-1],dp,n-1)+solver(arr,target,dp,n-1);
      }
      else dp[n][target]=solver(arr,target,dp,n-1);
      return dp[n][target];
  }
    int perfectSum(vector<int>& arr, int target) {
      
        int n=arr.size();
        //return solver(0,arr,target,n);
        vector<vector<int>>dp(n+1, vector<int>(target+1,-1));
        return solver(arr, target,dp,n);
    }
};