class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i: nums){
            mp[i]++;
        }
        for(auto p: mp){
            if(k==0){
                if((p.second>1))ans++;
               
            }
             else if(mp.count(p.first+k))ans++;
        }
        return ans;
    }
};