#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int atMost(vector<int>&nums, int goal){
        if(goal<0)return 0;
        int i=0,j=0,n=nums.size(),sum=0,cnt=0;
        while(j<n){
            sum+=nums[j];
            while(sum>goal){
                sum-=nums[i];
                i++;
            }
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)nums[i]=0;
            else nums[i]=1;
        }
        return atMost(nums,k)-atMost(nums,k-1);
    }
};