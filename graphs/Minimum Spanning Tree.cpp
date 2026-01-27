#include<vector>
#include<queue>

using namespace std;
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<bool>vis(V,false);
        int sum=0;
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,0});
        
        while(!pq.empty()){
            int node=pq.top().second;
            int cost=pq.top().first;
            pq.pop();
            if(vis[node])continue;
            vis[node]=true;
            sum+=cost;
            for(auto p: adj[node]){
                int neigh=p.first;
                int d=p.second;
                if(!vis[neigh]){
                    pq.push({d,neigh});
                }
            }
        }
        return sum;
    }
    
};