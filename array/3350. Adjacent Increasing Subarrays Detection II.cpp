#include <vector>
#include<climits>
using namespace std;
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int>inc(nums.size(),1),desc(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i])inc[i]=1+inc[i-1];
        }
        for(int i=(nums.size()-2);i>=0;i--){
            if(nums[i]<nums[i+1]){
                desc[i]=desc[i+1]+1;
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            ans=max(ans, min(inc[i],desc[i+1]));
        }
        return ans;
    }
};