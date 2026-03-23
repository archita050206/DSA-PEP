#include<iostream>
#include<vector>
using namespace std;
class Disjoint{
    public:

    vector<int>rank,parent;
    Disjoint(int n){
        rank.resize(n);
        parent.resize(n);
        for(int i=0;i<n;i++){
            rank[i]=0;
            parent[i]=i;
        }
    }
    int find(int node){
        if(parent[node]!=node){
            parent[node]=find(parent[node]);
        }
        return parent[node];

    }
    void unionByRank(int x, int y){// O(log n) for 1 ele
        int rootx=find(x);
        int rooty=find(y);
        if(rooty==rootx)return;
        if(rank[rootx]==rank[rooty]){
            parent[rooty]=rootx;
            rank[rootx]++;
        }
        else if(rank[rootx]<rank[rooty]){
        parent[rootx]=rooty;

        }
        else if(rank[rootx]>rank[rooty]){
            parent[rooty]=rootx;
        }
    }

};
int main(){
    Disjoint dis(6);
    dis.unionByRank(0,1);
    dis.unionByRank(1,4);
    dis.unionByRank(2,4);
    dis.unionByRank(2,5);
    if(dis.find(1)==dis.find(4))cout<<"1 and 4 belong to same group";
    return 0;
}