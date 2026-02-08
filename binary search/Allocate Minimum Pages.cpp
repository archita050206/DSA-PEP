#include<vector>
#include<algorithm>
using namespace std;
class Solution {
  public:
    bool calculate(vector<int>&nums, int mid, int k){
        int stud=1, pages=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid)return false;
            if(nums[i]+pages>mid){
                stud++;
                pages=nums[i];
            }
            else pages+=nums[i];
        }
        return (stud<=k)?true:false;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k > arr.size()) return -1;

        int s=0;
        for(int i:arr)s+=i;
        int l=*max_element(arr.begin(), arr.end()),h=s;
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            bool calc=calculate(arr,mid,k);
            if(calc){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};