#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    void dfs(int node,vector<int>&temp, vector<vector<int>>&ans,vector<vector<int>>& graph, int dest){
        temp.push_back(node);
        if(node==dest){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        for(int neigh: graph[node]){
            dfs(neigh,temp,ans,graph,dest);
        }
        temp.pop_back();

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>temp;
        dfs(0,temp,ans,graph,graph.size()-1);
        return ans;
    }
};