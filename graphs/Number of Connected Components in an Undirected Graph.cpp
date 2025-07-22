#include<vector>
#include<queue>

using namespace std;
class Solution {
  public:
    void dfs(int node, vector<bool>&visited,vector<vector<int>>& adj){
        if(visited[node])return;
        visited[node]=true;
        for(auto &i: adj[node]){
            dfs(i,visited,adj);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0;
        vector<bool>visited(n,false);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i, visited,adj);
                cnt++;
            }
            
        }
        return cnt;
    }
};  