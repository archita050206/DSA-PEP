#include<vector>
#include<queue>
#include<climits>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});

        }
        
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
           
            for(auto p: adj[node]){
                int neigh=p.first;
                int cost=p.second;
                if(cost+d<dist[neigh]){
                    dist[neigh]=cost+d;
                    pq.push({dist[neigh],neigh});
                }
            }
        }
        int maxval=INT_MIN;
        for(int i=1;i<n+1;i++){
            if(dist[i]==INT_MAX)return -1;
            maxval=max(maxval,dist[i]);
        }
        return maxval;
    }
};