#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0, j=0,len=-1;
        unordered_map<int,int>mp;
        int n=nums.size();
        while(j<n){
            if(!mp.count(nums[j]) || mp[nums[j]]<k){
                mp[nums[j]]++;
                len=max(len,j-i+1);
                j++;
            }
            else{
                mp[nums[i]]--;
                
                i++;
            }
        }
        return len;
    }
};