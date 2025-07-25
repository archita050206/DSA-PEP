#include<vector>
#include<queue>
#include<climits>

using namespace std;
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int>dist(V, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto p: adj[node]){
                int neigh=p.first;
                int cost=p.second;
                if(d+cost<dist[neigh]){
                    dist[neigh]=d+cost;
                    pq.push({dist[neigh],neigh});
                }
            }
        }
        return dist;
    }
};