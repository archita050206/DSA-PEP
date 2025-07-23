#include<vector>
#include<queue>
using namespace std;
class Solution {
  public:
    bool bfs(int n, vector<bool>&visited,vector<vector<int>>&adj){
        queue<pair<int,int>>q;
        
        q.push({n,-1});
        visited[n]=true;
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto &i: adj[node]){
                if(visited[i] && i!=parent)return true;
           
                 else   if(!visited[i]){
                        q.push({i,node});
                        visited[i]=true;
                    }
                
            }
        }
        return false;
        
    }
    bool dfs(int node, vector<bool>&visited,int parent, vector<vector<int>>&adj ){
        visited[node]=true;
        for(auto & child: adj[node]){
            if(!visited[child]){
                if(dfs(child,visited,node,adj))return true;
            }
            else if(visited[child] &&  child!=parent)return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        vector<bool>visited(V,false);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<V;i++){
            if(!visited[i]&& bfs(i,visited,adj)){
                return true;
            }
            // if(!visited[i] && dfs(i,visited,-1,adj)){
            //     return true;
            // }
        }
        return false;
        
    }
};