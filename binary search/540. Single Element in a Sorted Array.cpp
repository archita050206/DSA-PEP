#include<vector>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-1,ans=-1;
        while(l<h){
            int mid=l+(h-l)/2;
            if(mid%2==0){
                if(nums[mid]!=nums[mid+1]){
                    h=mid;
                }
                else l=mid+1;
            }
            else{
                if(nums[mid-1]!=nums[mid]){
                    h=mid;
                }
                else l=mid+1;
            }
        }
        return nums[l];
        
    }
};