#include <vector>
#include <queue>
#include<climits>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        queue<vector<int>>q;
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            adj[u].push_back({v,w});
        }
        q.push({src,0,0});
        vector<int>dist(n,INT_MAX);
        while(!q.empty()){
            int node=q.front()[0];
            int cost=q.front()[1];
            int steps=q.front()[2];
            q.pop();
            if(steps>k)continue;
            for(auto p: adj[node]){
                int w=p.second;
                int neigh=p.first;
                if(w+cost<dist[neigh]){
                    dist[neigh]=w+cost;
                    q.push({neigh,w+cost,steps+1});
                }
            }
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};