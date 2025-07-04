#include <vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0, h=nums.size()-1;
         vector<int>ans(2,-1);
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target){
                ans[0]=mid;
                h=mid-1;
            }
            else if(nums[mid]>target)h=mid-1;
            else l=mid+1;
        }
        l=0,h=nums.size()-1;
         while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target){
                ans[1]=mid;
                l=mid+1;
            }
            else if(nums[mid]>target)h=mid-1;
            else l=mid+1;
        }
       
        
        return ans;
        
    }
};