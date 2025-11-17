#include<vector>
using namespace std;
class Solution {
  public:
    double solver(vector<vector<double>>&dp, int row, int col, int k){
        if(col<1 || col>row)return 0.0;
        if(col==1 && row==1)return k;
        if(dp[row][col]!=-1.0)return dp[row][col];
        
        double lParent=solver(dp,row-1,col-1,k);
        double rParent=solver(dp,row-1,col,k);
        
        double lOverflow=max(0.0, lParent-1.0);
        double rOverflow=max(0.0, rParent-1.0);
        
        return dp[row][col]=(lOverflow+rOverflow)/2.0;
    }
    double waterOverflow(int K, int R, int C) {
        // code here
        vector<vector<double>>dp(R+1, vector<double>(R+1,-1.0));
        return min(1.0, solver(dp,R,C,K));
    }
};