#include<vector>
#include<algorithm>
using namespace std;
int longestSubarrayWithSumK(vector<int> nums, long long k) {
    // Write your code here
    int i=0,j=0,maxi=-1;
    long long sum=0;
        int n=nums.size();
        while(j<n){
            sum+=nums[j];
            while(sum>k){
                sum-=nums[i];
                i++;
            }
            if(sum==k){
                maxi=max(maxi, j-i+1);

            }
            j++;
        }
        return maxi;
}