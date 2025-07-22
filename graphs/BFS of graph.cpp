#include<vector>
#include<queue>

using namespace std;
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        queue<int>q;
        q.push(0);
        vector<int>ans;
        vector<bool>visited(adj.size(),false);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            
                    ans.push_back(x);
                   visited[x]=true; 
            
            for(int i=0;i<adj[x].size();i++){
                int node=adj[x][i];
                if(!visited[node]){
                
                q.push(node);
                visited[node]=true;
                }
            }
        }
        return ans;
        vector<int>ans;
        
    // vector<bool>visited(n,false);
    // queue<int>q;
    // q.push(0);
    // visited[0]=true;
    // while(!q.empty()){
    //     int x=q.front();
    //     q.pop();
    //     ans.push_back(x);
    //     for(auto &i: adj[x]){
    //         if(!visited[i]){
    //             q.push(i);
    //             visited[i]=true;
    //         }
    //     }
    // }
    // return ans;
        
    }
};