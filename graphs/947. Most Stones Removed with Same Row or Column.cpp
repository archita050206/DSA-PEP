#include <vector>
#include <unordered_set>
#include<climits>
using namespace std;
class Disjoint{
    public:
    vector<int>par,rank;
    Disjoint(int v){
        par.resize(v);
        rank.resize(v,0);
        for(int i=0;i<v;i++){
            par[i]=i;
        }
    }
    int find(int node){
        if(par[node]==node)return node;
        return par[node]=find(par[node]);
    }
    void unionNodes(int u, int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv)return;
        else if(rank[pu]<rank[pv]){
            par[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            par[pv]=pu;
        }
        else{
            par[pv]=pu;
            rank[pu]++;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow=INT_MIN, maxCol=INT_MIN;
        for(auto p: stones){
            maxRow=max(maxRow,p[0]);
            maxCol= max(maxCol,p[1]);

        }
        Disjoint ds(maxRow+maxCol+2);
        unordered_set<int>st;
        for(auto p: stones){
            int row=p[0];
            int col=p[1]+maxRow+1;
            ds.unionNodes(row,col);
            st.insert(ds.find(row));
            st.insert(ds.find(col));
        }
        int comp=0;
        for(int i:st){
            if(ds.find(i)==i)comp++;
        }
        return stones.size()-comp;
    }
};