#include<vector>
#include<queue>

using namespace std;
class Solution {
public:
    int dfs(int i, int j, int n, int m, vector<vector<int>>&grid){
        if(i<0 ||j<0||i>=n||j>=m||grid[i][j]==0)return 0;
        grid[i][j]=0;
        int area=1;
        area+=dfs(i-1,j,n,m,grid);
        area+=dfs(i,j-1,n,m,grid);
        area+=dfs(i+1,j,n,m,grid);
        area+=dfs(i,j+1,n,m,grid);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxArea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int area=dfs(i,j,n,m,grid);
                    maxArea=max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};