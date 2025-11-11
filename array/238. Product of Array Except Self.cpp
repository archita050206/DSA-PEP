#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pro=1,zcount=0;
        for(int i: nums){
            if(i==0)zcount++;
            if(i!=0)pro*=i;
        }
        for(int i=0;i<nums.size();i++){
            if(zcount>1)nums[i]=0;
            else if(zcount==1){
                if(nums[i]==0)nums[i]=pro;
                else nums[i]=0;
            }
            else nums[i]=pro/nums[i];
        }
        return nums;
    }
};