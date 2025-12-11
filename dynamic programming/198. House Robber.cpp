#include <vector>
#include <queue>

using namespace std;
class Solution
{
public:
    int solver(vector<int> &nums, int i, vector<int> &dp, int n)
    {

        if (i >= n)
            return 0;
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int steal = nums[i] + solver(nums, i + 2, dp, n);
        int skip = solver(nums, i + 1, dp, n);
        return dp[i] = max(steal, skip);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        // Memoisation
        //     vector<int>dp(n,-1);
        //    return solver(nums,0,dp,n); --> for memoisation

        //Tabulation
        if (n <= 1)
            return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
        {
            //  dp[i]=max(nums[i]+dp[i-2], dp[i-1]);
            int steal = nums[i] + dp[i - 2];
            int skip = dp[i - 1];
            dp[i] = max(steal, skip);
        }
        return max(dp[n - 1], dp[n - 2]);
    }
};