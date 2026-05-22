#include<vector>
#include<queue>

using namespace std;

class Solution {
  public:
    void dfs(int node, vector<vector<int>>&adj, vector<bool>&visited ){
        if(visited[node])return;
        visited[node]=true;
        for(int i: adj[node]){
            if(!visited[i])dfs(i,adj,visited);
        }
    }
    int isEulerCircuit(int V, vector<vector<int>>& adj) {
        // code here
        int start=-1;
        for(int i=0;i<V;i++){
            if(adj[i].size()>0){
                start=i;
                break;
            }
        }
        if(start==-1)return 2;
        vector<bool>visited(V,false);
        dfs(start,adj,visited);
        for(int i=0;i<V;i++){
            if(adj[i].size()>0 && !visited[i])return 0;
            
        }
        int odd=0;
        for(int i=0;i<V;i++){
            if(adj[i].size()%2!=0)odd++;
        }
        if(odd==0)return 2;
        if(odd==2)return 1;
        return 0;
        
    }
};