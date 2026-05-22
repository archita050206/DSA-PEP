#include<vector>
#include<queue>

using namespace std;
class Solution {
  public:
    bool dfs(int node,  vector<vector<int>>&adj, vector<bool>&visited, int count, int n){
        if(count==n)return true;
        visited[node]=true;
        for(int i: adj[node]){
            if(!visited[i]){
                if(dfs(i,adj,visited,count+1,n))return true;
                
            }
        }
        visited[node]=false;
        return false;
    }
    bool check(int n, int m, vector<vector<int>> edges) {
        // code here
        vector<vector<int>>adj(n+1);
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<n;i++){
            vector<bool>visited(n+1);
            if(dfs(i,adj, visited,1,n))return true;
            
        }
        return false;
    }
};
