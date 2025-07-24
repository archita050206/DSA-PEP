#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
bool isCycle(int node,vector<int>&visited,vector<bool>&inRecursion,vector<vector<int>>& graph ){
    if(visited[node]==1)return true;
    if(visited[node]==2)return false;
    visited[node]=1;
    for(int neigh: graph[node]){
        if(isCycle(neigh,visited,inRecursion,graph))return true;
    }
    visited[node]=2;
    return false;

}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>visited(v,0);//0-> !visited, 1->visited, 2->safe
        vector<bool>inRecursion(v,false);
        vector<int>ans;
        for(int i=0;i<v;i++){
            if(!isCycle(i,visited,inRecursion,graph)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};