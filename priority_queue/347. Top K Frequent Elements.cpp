#include<vector>
#include<unordered_map>

#include<queue>

using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i: nums){
            mp[i]++;
        }
        vector<int>ans;
        // vector<pair<int,int>>v(mp.begin(),mp.end());
        // sort(v.begin(),v.end(), [](const pair<int,int>&a, const pair<int,int>&b){
        //     return a.second>b.second;
        // });
        
        // for(int i=0;i<k;i++){
        //     ans.push_back(v[i].first);
        // }
        priority_queue<pair<int,int>>pq;
        for(auto p: mp){
            pq.push({p.second,p.first});
        }
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};