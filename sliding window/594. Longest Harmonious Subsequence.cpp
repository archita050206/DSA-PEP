#include<climits>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i: nums){
            mp[i]++;
        }
        int len=0;
        for(auto p: mp){
            int x=p.first;
            if(mp.count(x+1))len=max(len, mp[x]+mp[x+1]);

        }
        return len;
    }
};