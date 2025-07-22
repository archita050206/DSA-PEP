#include<vector>
#include<queue>

using namespace std;
class Solution {
public:
void dfs(int i, int j,vector<vector<bool>>&visited ,int m,int n,vector<vector<char>>& grid){
    if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0' || visited[i][j])return;
    visited[i][j]=true;
    dfs(i-1,j,visited,m,n,grid);//top
    dfs(i+1,j,visited,m,n,grid);//bottom
    dfs(i,j-1,visited,m,n,grid);//left
    dfs(i,j+1,visited,m,n,grid);//right

}
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((grid[i][j]=='1') && (!visited[i][j])){
                    dfs(i,j,visited,m,n,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};