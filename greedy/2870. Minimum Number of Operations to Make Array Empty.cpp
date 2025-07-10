#include<unordered_map>
#include<vector>
#include<cmath>

using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i: nums){
            mp[i]++;
        }
        int cnt=0;
        for(auto p: mp){
            
            if(p.second==1){
                return -1;
            }
            cnt+=ceil((double)p.second/3);
        }
        return cnt;
    }
};