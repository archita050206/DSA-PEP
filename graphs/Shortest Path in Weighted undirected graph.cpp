#include<unordered_map>
#include<queue>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        int src=1, dst=n;
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int>parent(n+1,-1);
        vector<int>dist(n+1,INT_MAX);
        vector<int>ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,src});
        dist[src]=0;
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto p: adj[node]){
                int neigh=p.first;
                int cost=p.second;
                if(d+cost<dist[neigh]){
                    dist[neigh]=d+cost;
                    pq.push({dist[neigh], neigh});
                    parent[neigh]=node;
                }
            }
        }
        if(dist[n]==INT_MAX)return {-1};
        int curr=dst;
        while(curr!=-1){
            ans.push_back(curr);
            curr=parent[curr];
        }
        ans.push_back(dist[n]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};