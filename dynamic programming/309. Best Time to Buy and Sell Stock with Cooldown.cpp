#include<vector>
using namespace std;
class Solution {
public:
    // int solver(int i, bool canBuy, vector<vector<int>>&dp, vector<int>&prices){
    //     if(i>=prices.size())return 0;
    //     if(dp[i][canBuy]!=-1)return dp[i][canBuy];
    //     if(canBuy){
    //         return dp[i][canBuy]=max(-prices[i]+solver(i+1,false,dp,prices), solver(i+1,true,dp,prices));
    //     }
    //     else{
    //        return dp[i][canBuy]=max(prices[i]+solver(i+2,true,dp,prices), solver(i+1,false,dp,prices));
    //     }
    // }
    int maxProfit(vector<int>& prices) {
       
        // vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        // return solver(0,true,dp,prices);
        vector<int>a1(2,-1),a2(2,-1),curr(2,-1);
        for(int i=prices.size()-1;i>=0;i--){
            curr[1]=max(-prices[i]+a1[0],a1[1]);
            curr[0]=max(prices[i]+a2[1],a1[0]);
            a2=a1;
            a1=curr;
        }
        return curr[1]+1;
    }
};