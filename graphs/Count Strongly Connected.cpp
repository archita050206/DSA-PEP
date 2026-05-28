#include<vector>
#include<stack>

using namespace std;
class Solution {
  public:
    void dfs(int node, vector<bool>&visited, vector<vector<int>>&adj, stack<int>&st){
        if(visited[node])return;
        visited[node]=true;
        for(int neigh: adj[node]){
            if(!visited[neigh]){
                dfs(neigh,visited,adj,st);
            }
        }
        st.push(node);
    }
    void dfs2(int node, vector<bool>&visited, vector<vector<int>>&adj){
        if(visited[node])return;
        visited[node]=true;
        for(int neigh: adj[node]){
            if(!visited[neigh]){
                dfs2(neigh,visited,adj);
            }
        }
        
    }
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        vector<bool>visited(V,false);
        vector<vector<int>>adj(V);
        for(auto p: edges){
            int u=p[0];
            int v=p[1];
            adj[u].push_back(v);
        }
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,visited,adj,st);
            }
        }
        vector<vector<int>>adjT(V);
        for(int i=0;i<V;i++){
            for(int neigh: adj[i]){
                // i->neigh
                // neigh->i
                adjT[neigh].push_back(i);
            }
        }
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        int cnt=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
            if(!visited[node]){
                cnt++;
                dfs2(node,visited,adjT);
            }
        }
        return cnt;
        
    }
};