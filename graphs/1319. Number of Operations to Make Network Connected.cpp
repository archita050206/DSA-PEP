#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Disjoint{
    public:
    vector<int>par,rank;
    Disjoint(int n){
        par.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    int find(int node){
        if(par[node]==node)return node;
        return par[node]=find(par[node]);
    }
    bool unionNodes(int u, int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv)return false;//donot need extra cablee
        else if(rank[pu]<rank[pv]){
            par[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            par[pv]=pu;
        }
        else{
            par[pu]=pv;
            rank[pv]++;
        }
        return true;

    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges=connections.size();
        Disjoint ds(n);
        if(edges<(n-1))return -1;
        int extras=0;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            if(!ds.unionNodes(u,v)){
                extras++;
            }
        }
        int components=0;
        for(int i=0;i<n;i++){
            if(ds.find(i)==i)components++;
        }
        return (extras>=(components-1))?(components-1):-1;
    }
};