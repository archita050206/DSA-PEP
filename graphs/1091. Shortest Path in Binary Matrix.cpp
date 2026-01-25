#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int steps=1;
        queue<pair<int,int>>q;
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;
        q.push({0,0});
        grid[0][0]=1;
        while(!q.empty()){
            int size=q.size();
            for(int k=0;k<size;k++){

           
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(i==(n-1) && j==(n-1))return steps;
            //top left
            if((i-1>=0 && j-1>=0) && grid[i-1][j-1]==0){
                grid[i-1][j-1]=1;
                q.push({i-1,j-1});
            }
            //top right
            if((i-1>=0 && j+1<n) && grid[i-1][j+1]==0){
                grid[i-1][j+1]=1;
                q.push({i-1,j+1});
            }
            //bottom left
            if((i+1<n && j-1>=0) && grid[i+1][j-1]==0){
                grid[i+1][j-1]=1;
                q.push({i+1,j-1});
            }
            //bottom right
            if((i+1<n && j+1<n) && grid[i+1][j+1]==0){
                grid[i+1][j+1]=1;
                q.push({i+1,j+1});
            }
            //top
            if((i-1>=0) && grid[i-1][j]==0){
                grid[i-1][j]=1;
                q.push({i-1,j});
            }
            //bottom
            if((i+1<n) && grid[i+1][j]==0){
                grid[i+1][j]=1;
                q.push({i+1,j});
            }
            //left
            if((j-1>=0) && grid[i][j-1]==0){
                grid[i][j-1]=1;
                q.push({i,j-1});
            }
            //right
            if((j+1<n) && grid[i][j+1]==0){
                grid[i][j+1]=1;
                q.push({i,j+1});
            }
             }
             steps++;
        }
        return -1;
    }
};