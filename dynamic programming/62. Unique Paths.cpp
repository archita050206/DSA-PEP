#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int solver(int i,int j, int n, int m){
        if(i==(n-1) && (j==(m-1)))return 1;
        if(i>=n || j>=m)return 0;
        return solver(i+1,j,n,m)+solver(i,j+1,n,m);
    }
    int solver(int i, int j, int n, int m,  vector<vector<int>>&dp){
        if(i==(m-1) && (j==(n-1)))return 1;
        if(i>=m || j>=n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=solver(i+1,j,n,m,dp)+solver(i,j+1,n,m,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,-1));
        //return solver(0,0,n,m);
        //return solver(0,0,n,m,dp);
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};