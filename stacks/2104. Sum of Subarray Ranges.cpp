#include <stack>
#include <vector>
#include <string>

using namespace std;
class Solution
{
public:
    vector<int> nextS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            if (!st.empty())
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            if (!st.empty())
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nextG(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            if (!st.empty())
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevG(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            if (!st.empty())
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    long long subArrayRanges(vector<int> &nums)
    {
        int n = nums.size();
        long long sum1 = 0, sum2 = 0;
        vector<int> pge = prevG(nums);
        vector<int> nge = nextG(nums);
        vector<int> pse = prevS(nums);
        vector<int> nse = nextS(nums);
        for (int i = 0; i < n; i++)
        {
            int left1 = i - pge[i];
            int right1 = nge[i] - i;
            long long cnt1 = 1LL * left1 * right1;
            sum1 = sum1 + (cnt1 * nums[i]);
            int left2 = i - pse[i];
            int right2 = nse[i] - i;
            long long cnt2 = 1LL * left2 * right2;
            sum2 = sum2 + (cnt2 * nums[i]);
        }
        return abs(sum1 - sum2);
    }
};