#include <bits/stdc++.h> 
using namespace std;
void dfs(int node,vector<bool>&visited, stack<int>&st, vector<vector<int>>&adj ){
    visited[node]=true;
    for(int child: adj[node]){
        if(!visited[child]){
            dfs(child,visited,st,adj);
        }
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    stack<int>st;
    vector<bool>visited(v);
    vector<vector<int>>adj(v);
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i,visited,st,adj);
        }
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}