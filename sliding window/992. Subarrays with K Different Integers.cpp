#include<climits>
#include<vector>
#include<unordered_map>
using namespace std;

// if we want exactly k, then in sliding window atmost k is easy do search for atmost k and atmost k-1
// now atmost k - atmost (k-1) only contains those elements which are exactly k

class Solution {
public:
    int atmostK(vector<int>&nums, int k){
        unordered_map<int,int>mp;
        int i=0,j=0;
        int cnt=0;
        while(j<nums.size()){
            mp[nums[j]]++;
            
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
            if(mp.size()<=k){
                cnt+=j-i+1;
            }
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostK(nums,k)-atmostK(nums,k-1);
    }
};