#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int countHousePlacements(int n) {
        
        if(n==1)return 4;
        else if(n==2)return 9;
        vector<long long>dp(n+1,0);
        long long mod=1e9+7;
        dp[1]=2;
        dp[2]=3;
        for(int i=3;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2])%mod;

        }
        return (dp[n]*dp[n])%mod;
    }
};