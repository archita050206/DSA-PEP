#include<iostream>
#include<vector>

#include<map>
using namespace std;

int main(){
    vector<pair<int,int>>edgeList={{1,2},{2,3},{3,5},{5,6},{6,4},{4,3},{1,7},{4,7}};
    map<int,vector<int>>mp;
    for(auto p: edgeList){
        int u=p.first;
        int v=p.second;
        mp[u].push_back(v);
        mp[v].push_back(u);

    }
    for(auto p: mp){
        cout<<p.first<<" : ";
        for(int i: p.second){
            cout<<i<<' ';
        }
        cout<<endl;
    }

    vector<vector<int>>adjMatrix(8,vector<int>(8,0));
    for(auto p: edgeList){
        int u=p.first;
        int v=p.second;
        adjMatrix[u][v]=1;
        adjMatrix[v][u]=1;
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<adjMatrix[i][j];
        }
        cout<<endl;
    }
  
}