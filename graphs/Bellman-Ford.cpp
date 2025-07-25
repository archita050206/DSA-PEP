#include<vector>
#include<queue>

using namespace std;
// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        
        vector<int>dist(V,100000000);
        dist[src]=0;
        for(int k=1;k<V;k++){
            
            for(auto vect: edges){
                int u=vect[0];
                int v=vect[1];
                int w=vect[2];
                if(dist[u]!=100000000 && dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                }
            }
            
        }
        for(auto vect: edges){
            int u=vect[0];
                int v=vect[1];
                int w=vect[2];
            if(dist[u]!=100000000 && dist[u]+w<dist[v])return {-1};
        }
        return dist;
    }
};
