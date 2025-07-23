#include<vector>
#include<queue>

using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0,time=0;
        queue<pair<int,int>>q;
        int row=grid.size()-1;
        int col=grid[0].size()-1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)fresh++;
                else if(grid[i][j]==2)q.push({i,j});
            }
        }
        while(!q.empty() && fresh>0){
            int size=q.size();
            
            for(int k=0;k<size;k++){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if((i-1)>=0){//top
                    if(grid[i-1][j]==1){
                        grid[i-1][j]=2;
                        q.push({i-1,j});
                        fresh--;
                    }

                }
                if((j-1)>=0){//left
                    if(grid[i][j-1]==1){
                        grid[i][j-1]=2;
                        q.push({i,j-1});
                        fresh--;
                    }
                }
                if((i+1)<=row){//bottom
                    if(grid[i+1][j]==1){
                        grid[i+1][j]=2;
                        q.push({i+1,j});
                        fresh--;
                    }
                }
                if((j+1)<=col){//right
                    if(grid[i][j+1]==1){
                        grid[i][j+1]=2;
                        q.push({i,j+1});
                        fresh--;
                    }
                }

            }
            time++;
            
        }
        return (fresh==0)?time:-1;
        
    }
};