#include<vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int cnt=0,sum=0;
        int n=nums.size();
        mp[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum-k;
            if(mp.count(rem)){
                cnt+=mp[rem];
            }
            mp[sum]++;
        }
        return cnt;
    }
};