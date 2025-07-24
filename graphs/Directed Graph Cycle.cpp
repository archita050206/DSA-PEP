#include<vector>
#include<queue>

using namespace std;
class Solution {
  public:
  bool cycle(int node,vector<bool>&visited, vector<bool>&inRecursion, vector<vector<int>>&adj ){
      visited[node]=true;
      inRecursion[node]=true;
      for(int i: adj[node]){
          if(visited[i] && inRecursion[i])return true;
          else if(!visited[i] && cycle(i,visited,inRecursion, adj))return true;
          
      }
      inRecursion[node]=false;
      return false;
      
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        vector<vector<int>>adj(V);
        vector<bool>visited(V,false);
        vector<bool>inRecursion(V,false);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        for(int i=0;i<V;i++){
            if(!visited[i] && cycle(i,visited,inRecursion,adj))return true;
        }
        return false;
    }
};