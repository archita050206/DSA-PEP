#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int w=roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<long long>dist(n,LLONG_MAX), ways(n,0);
        ways[0]=1;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>>pq;
        pq.push({0,0});
        dist[0]=0;
        while(!pq.empty()){
            long long cost=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(cost>dist[node])continue;
            for(auto p: adj[node]){
                int neigh=p.first;
                long long d=p.second;
                if(cost+d<dist[neigh]){
                    dist[neigh]=cost+d;
                    pq.push({cost+d, neigh});
                    ways[neigh]=ways[node];
                }
                else if(cost+d==dist[neigh]){
                    ways[neigh]=(ways[neigh]+ways[node])%MOD;
                }
            }
        }
        return ways[n-1];
    }
};