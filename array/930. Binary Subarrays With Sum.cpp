#include <unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        unordered_map<int,int>mp;
        int sum=0, cnt=0;
        int n=nums.size();
                mp[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum-goal;
            if(mp.count(rem)){
                cnt+=mp[rem];
            }
            mp[sum]++;
        }
        return cnt;
    }
};