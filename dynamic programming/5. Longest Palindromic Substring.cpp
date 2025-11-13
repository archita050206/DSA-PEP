#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n==0)return "";
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        int start=0,maxLen=1;
        for(int len=2;len<=n;len++){
            for(int i=0;len+i-1<n;i++){
                int j=len+i-1;
                if(s[i]==s[j]){
                    if(len==2|| dp[i+1][j-1]){
                        dp[i][j]=true;
                        if(len>maxLen){
                            maxLen=len;
                            start=i;
                        }
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }
};