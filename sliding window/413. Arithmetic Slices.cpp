
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3)return 0;
        int diff=nums[1]-nums[0],cnt=0,curr=0;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]-nums[i-1]==nums[i+1]-nums[i]){
                curr+=1;
                cnt+=curr;
            }
            else curr=0;
        }
        return cnt;
    }
};