#include<climits>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int target) {
        if(target<=1)return 0;
        int i=0,j=0;int n=nums.size(),cnt=0;
        long long pro=1;
        while(j<n){
            pro*=nums[j];
            while(pro>=target){
                pro=pro/nums[i];
                i++;
            }
            if(pro<target){
                cnt+=j-i+1;
                
            }
            j++;
        }
        return cnt;
    }
};