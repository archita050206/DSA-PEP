#include<vector>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;
class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        // priority_queue<int>pq;
        // vector<int>ans;
        // for(int i=0;i<a.size();i++){
        //     for(int j=0;j<b.size();j++){
        //         pq.push(a[i]+b[j]);
        //     }
        // }
        // for(int i=0;i<k && !pq.empty();i++){
        //     ans.push_back(pq.top());
        //     pq.pop();
        // }
        // return ans;
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        int i=0,j=0;
        priority_queue<pair<int,pair<int,int>>>pq;
        set<pair<int,int>>st;
        st.insert({0,0});
        pq.push({a[i]+b[j],{0,0}});
        vector<int>ans;
        while(k>0 && !pq.empty()){
            int sum=pq.top().first;
            i=pq.top().second.first;
            j=pq.top().second.second;
            pq.pop();
            ans.push_back(sum);
            if((i+1)<a.size() && st.find({i+1,j})==st.end()){
                pq.push({a[i+1]+b[j],{i+1,j}});
                st.insert({i+1,j});
                
            }
            if((j+1)<b.size() && st.find({i,j+1})==st.end()){
                pq.push({a[i]+b[j+1],{i,j+1}});
                st.insert({i,j+1});
                
            }
            k--;
            
        }
        return ans;
    }
};