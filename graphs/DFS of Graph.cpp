#include<vector>
#include<queue>

using namespace std;
class Solution {
  public:
    void dfsHelper(vector<vector<int>>& adj, int node, vector<bool>&visited, vector<int>&ans){
      if(visited[node])return;
      ans.push_back(node);
      visited[node]=true;
      for(auto &i: adj[node]){
          dfsHelper(adj,i,visited,ans);
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<bool>visited(adj.size(),false);
        vector<int>ans;
        dfsHelper(adj,0,visited,ans);
        return ans;
    }
};  