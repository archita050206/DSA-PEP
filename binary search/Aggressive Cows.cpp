#include<vector>
#include<algorithm>
using namespace std;
class Solution {
  public:
    int toSet(vector<int>&nums, int mid, int k){
        int cnt=1,last=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]-last>=mid){
                cnt++;
                last=nums[i];
            }
            
        }
        return (cnt>=k)?true:false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(), stalls.end());
        int l=1,h=*max_element(stalls.begin(),stalls.end())-*min_element(stalls.begin(),stalls.end());
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int val=toSet(stalls,mid,k);
            if(val){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};