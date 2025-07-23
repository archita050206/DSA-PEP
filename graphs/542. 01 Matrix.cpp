#include<vector>
#include<queue>

using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<bool>>visited(row, vector<bool>(col,false));
        queue<pair<int,int>>q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==0){
                visited[i][j]=true;
                q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int size=q.size();
            for(int k=0;k<size;k++){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                //top
                if((i-1)>=0 && !visited[i-1][j]){
                    q.push({i-1,j});
                    visited[i-1][j]=true;
                    mat[i-1][j]=mat[i][j]+mat[i-1][j];

                }
                //down
                if((i+1)<row && !visited[i+1][j]){
                    q.push({i+1,j});
                    visited[i+1][j]=true;
                    mat[i+1][j]=mat[i][j]+mat[i+1][j];

                }
                //left
                if((j-1)>=0 && !visited[i][j-1]){
                    q.push({i,j-1});
                    visited[i][j-1]=true;
                    mat[i][j-1]=mat[i][j]+mat[i][j-1];

                }
                //right
                if((j+1)<col && !visited[i][j+1]){
                    q.push({i,j+1});
                    visited[i][j+1]=true;
                    mat[i][j+1]=mat[i][j]+mat[i][j+1];

                }
            }

        }
        return mat;

    }
};