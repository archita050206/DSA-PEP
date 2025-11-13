#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        if(n<=1)return n;
        vector<vector<bool>>dp(n, vector<bool>(n,false));
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt++;
            dp[i][i]=true;
        }
        for(int len=2;len<=n;len++){
            for(int i=0;len+i-1<n;i++){
                int j=len+i-1;
                if(s[i]==s[j]){
                    if(len==2 || dp[i+1][j-1]){
                        dp[i][j]=true;
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};