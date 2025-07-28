#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int,int>>q;
        int n=matrix.size(); //--> rows
        int m=matrix[0].size(); // --> col
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<n;k++){
                matrix[k][j]=0;
            }
            for(int k=0;k<m;k++){
                matrix[i][k]=0;
            }
        }
        


    }
};