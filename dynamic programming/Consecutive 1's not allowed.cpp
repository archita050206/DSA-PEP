
#include<vector>

using namespace std;
// User function template for C++
class Solution {
  public:
    // #define ll long long
    int countStrings(int n) {
        // code here
        vector<int>dp(n+1,0);
        dp[1]=2;
        dp[2]=3;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};