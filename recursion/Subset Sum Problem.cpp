#include<vector>
#include<string>

using namespace std;
class Solution
{
public:
    bool solver(int i, vector<int> &arr, int target, int n)
    {

        if (target == 0)
        {
            return true;
        }
        if (target < 0 || i >= n)
            return false;
        return solver(i + 1, arr, target - arr[i], n) ||
               solver(i + 1, arr, target, n);
    }

    bool isSubsetSum(vector<int> &arr, int target)
    {
        // code here
        // int n = arr.size();
        // return solver(0, arr, target, n);
        int n=arr.size();
        //return solver(0,arr,target,n);
        vector<vector<bool>>dp(n+1,vector<bool>(target+1));
        
        for(int i=0;i<target;i++){
            dp[0][i]=false;
        }
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][target];
    }
};