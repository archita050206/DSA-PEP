#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        vector<int>indegree(numCourses);
        vector<vector<int>>adj(numCourses);
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<prereq.size();i++){
            int u=prereq[i][1];
            int v=prereq[i][0];
            adj[u].push_back(v);
        }
        for(int i=0;i<numCourses;i++){
            for(int neigh: adj[i]){
                indegree[neigh]++;
            }
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int neigh: adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0)q.push(neigh);
            }
        }
        if(ans.size()==numCourses)return ans;
        return {};
    }
};