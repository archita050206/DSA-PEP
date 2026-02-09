#include<climits>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool getSum(vector<int>&nums, int target, int k){
        int sum=0,cnt=1,tsum=0;
        for(int i:nums){
            tsum+=i;
        }
        for(int i: nums){
            if((sum+i)>target){
                cnt++;
                sum=i;
            }
            else sum+=i;
        }
        
        
        return (cnt<=k)?true:false;

    }
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end()), n=nums.size(),sum=0;
        for(int i: nums){
            sum+=i;
        }
        int h=sum,ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            bool b=getSum(nums,mid,k);
            if(b){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};