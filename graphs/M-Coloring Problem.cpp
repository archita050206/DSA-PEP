#include<vector>
#include<queue>

using namespace std;
class Solution {
  public:
    bool isSafe(int node, int col, vector<int>&colours, vector<vector<int>>&adj){
        for(int neigh: adj[node]){
            if(colours[neigh]==col)return false;
        }
        return true;
    }
    bool solver(int node, int m, int V, vector<int>&colours,vector<vector<int>>&adj){
        if(node==V)return true;
        for(int col=1;col<=m;col++){
            if(isSafe(node, col, colours, adj)){
                colours[node]=col;
                if(solver(node+1,m,V,colours,adj))return true;
                colours[node]=0;
            }
        }
        return false;
    }
    bool graphColoring(int V, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>>adj(V);
        for(auto p:edges){
            int u=p[0];
            int v=p[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>colours(V,0);
        return solver(0,m,V,colours,adj);
    }
};