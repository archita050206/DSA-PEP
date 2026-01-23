#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>&visited, vector<vector<int>>&grid,int n, int m){
        if(i<0||j<0||i>=n||j>=m||visited[i][j]||grid[i][j]==0)return;
        visited[i][j]=true;
        dfs(i+1,j,visited,grid,n,m);
        dfs(i-1,j,visited,grid,n,m);
        dfs(i,j+1,visited,grid,n,m);
        dfs(i,j-1,visited,grid,n,m);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<bool>>visited(n,vector<bool>(m, false));
        for(int i=0;i<n;i++){
            if(grid[i][0]==1)dfs(i,0,visited,grid,n,m);
            if(grid[i][m-1]==1)dfs(i,m-1,visited,grid,n,m);
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1)dfs(0,i,visited,grid,n,m);
            if(grid[n-1][i]==1)dfs(n-1,i,visited,grid,n,m);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1)cnt++;
            }
        }
        return cnt;
    }
};