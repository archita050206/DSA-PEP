#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
const long long  M=1e9+7;
    int solver( vector<vector<int>>&dp,vector<int>& loc, int fuel, int start, int finish){
        if(dp[start][fuel]!=-1)return dp[start][fuel];
        long long ways=(start==finish)?1:0;
        for(int city=0;city<loc.size();city++){
            if(city==start)continue;
            int cost=abs(loc[start]-loc[city]);
            if(fuel>=cost){
                ways+=solver(dp,loc,fuel-cost,city,finish);
                ways=ways%M;
            }
            
        }
        return dp[start][fuel]=ways;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>>dp(locations.size()+1, vector<int>(fuel+1,-1));
        return solver(dp,locations,fuel,start,finish);
    }
};