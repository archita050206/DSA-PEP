#include<vector>
#include<queue>

using namespace std;
class Solution {
  vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        vector<int>temp;
        temp.push_back(i);
        for(int j: adj[i]){
            temp.push_back(j);
        }
        ans.push_back(temp);

    }
    return ans;
}
};  