#include<vector>

using namespace std;
void dfs(int node,vector<bool>&visited, vector<int>&temp, vector<vector<int>>&adj ){
    if(visited[node])return;
    visited[node]=true;
    temp.push_back(node);
    for(auto &i:adj[node] ){
        if(!visited[i]){
            
            dfs(i,visited,temp,adj);
        }
    }

}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>>adj(V);
    vector<vector<int>>ans;
    for(int i=0;i<E;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int>temp;
            dfs(i,visited,temp, adj);
            ans.push_back(temp);
        }
    }
    return ans;
    
}