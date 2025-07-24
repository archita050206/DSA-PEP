#include <bits/stdc++.h> 
using namespace std;
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        queue<int>q;
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(int child:adj[i]){
                indegree[child]++;
            }
        }
        for(int i=0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int child: adj[node]){
                indegree[child]--;
                if(indegree[child]==0)q.push(child);
            }
        }
        return ans;
        
    }
};