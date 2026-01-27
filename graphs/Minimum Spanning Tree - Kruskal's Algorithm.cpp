// User function Template for C++
#include<vector>
#include<algorithm>

using namespace std;
class Disjoint{
    public:
    vector<int>rank,par;
    Disjoint(int V){
        rank.resize(V,0);
        par.resize(V);
        for(int i=0;i<V;i++){
            par[i]=i;
        }
        
    }
    int find(int x){
        if(par[x]==x)return x;
        return par[x]=find(par[x]);
    }
    void unionByPath(int u, int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv)return;
        else if(pu<pv){
            par[pu]=pv;
        }
        else if(pv<pu){
            par[pv]=pu;
        }
        else{
            par[pu]=pv;
            rank[pv]++;
        }
    }
};
class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        int sum=0;
        Disjoint ds(V);
        sort(edges.begin(),edges.end(),[](vector<int>&a, vector<int>&b){
            return a[2]<b[2];
        });
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            if(ds.find(u)!=ds.find(v)){
                sum+=w;
                ds.unionByPath(u,v);
            }
        }
        return sum;
    }
};