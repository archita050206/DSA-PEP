#include<vector>
#include<queue>

using namespace std;
class Solution {
public:
    bool dfs(int node, vector<vector<int>>&adj,vector<bool>&visited, vector<bool>&  inRecursion){
        visited[node]=true;
        inRecursion[node]=true;
        for(int neigh: adj[node]){
            if(visited[neigh] && inRecursion[neigh])return true;
            else if(!visited[neigh] && dfs(neigh,adj,visited,inRecursion))return true;
        }
        
        inRecursion[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<vector<int>>adj(numCourses);
        vector<bool>visited(numCourses,false);
        vector<bool>inRecursion(numCourses, false);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];
            adj[u].push_back(v);
        }
        // vector<int>indegree(numCourses);
        // for(int i=0;i<numCourses;i++){
        //     for(int child: adj[i]){
        //         indegree[child]++;
        //     }
        // }
        // queue<int>q;
        // for(int i=0;i<numCourses;i++){
        //     if(indegree[i]==0)q.push(i);
        // }
        // while(!q.empty()){
        //     int node=q.front();
        //     q.pop();
        //     ans.push_back(node);
        //     for(int neighbour: adj[node]){
        //         indegree[neighbour]--;
        //         if(indegree[neighbour]==0)q.push(neighbour);
        //     }
        // }
        // if(ans.size()==numCourses)return true;
        // return false;
       
        for(int i=0;i<numCourses;i++){
            if(!visited[i] && dfs(i,adj,visited, inRecursion)){
                return false;
            }
        }
        
        return true;
    }
};