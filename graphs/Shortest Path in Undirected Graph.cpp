#include<unordered_map>
#include<queue>
#include<vector>
#include<climits>
using namespace std;
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adjs, int src) {
        // code here
        int v=adjs.size();
        vector<vector<pair<int,int>>>adj(v);
        for(int i=0;i<v;i++){
            for(int val: adjs[i]){
                int u=i;
                int v=val;
                
                adj[u].push_back({v,1});
                adj[v].push_back({u,1});
            }
        }
        vector<int>dist(v,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            for(auto p: adj[node]){
                int neigh=p.first;
                int cost=p.second;
                if(d+cost<dist[neigh]){
                    dist[neigh]=d+cost;
                    pq.push({d+cost, neigh});
                }
            }
        }
       for(int i=0;i<v;i++){
           if(dist[i]==INT_MAX)dist[i]=-1;
       }
        return dist;
    }
};