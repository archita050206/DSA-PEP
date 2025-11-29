#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int solver(int i, int j, string &t1, string &t2, vector<vector<int>>&dp){
        if(i==t1.size() || j==t2.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(t1[i]==t2[j]){
            return dp[i][j]=1+solver(i+1,j+1,t1,t2,dp);
        }
        int skip1=solver(i+1,j,t1,t2,dp);
        int skip2=solver(i,j+1,t1,t2,dp);
        return dp[i][j]=max(skip1,skip2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
        // return solver(0,0,text1,text2,dp);
        int n=text1.length();
        int m=text2.length();
        vector<int>curr(m+1,-1),next(m+1,-1);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    curr[j]=1+next[j+1];

                }
                else curr[j]=max(curr[j+1],next[j]);
            }
            next=curr;
        }
        return curr[0]+1;
    }
};