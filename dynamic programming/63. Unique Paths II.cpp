#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
int solver(int i, int j, int n, int m, vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid){
    if(i==(n-1) && j==(m-1))return 1;
    if(i>=n || j>=m)return 0;
    if(obstacleGrid[i][j]==1)return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    return dp[i][j]=solver(i+1,j,n,m,dp,obstacleGrid)+solver(i,j+1,n,m,dp, obstacleGrid);

}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1)return 0;
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solver(0,0,n,m,dp,obstacleGrid);
        vector<vector<int>> dp(n, vector<int>(m));
        for(int i=0;i<n;i++){
            if(obstacleGrid[i][0]==1)break;
            dp[i][0]=1;

        }
        for(int i=0;i<m;i++){
            if(obstacleGrid[0][i]==1)break;
            dp[0][i]=1;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(obstacleGrid[i][j]==1)dp[i][j]=0;
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];

    }
};