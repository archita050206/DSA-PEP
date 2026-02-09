#include<vector>
#include<queue>
using namespace std;
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) {
        // Code here
        queue<pair<int,int>>q;
        int n=matrix.size();
        q.push({0,0});
        vector<int>ans;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(matrix[i][j]==-1)continue;
            ans.push_back(matrix[i][j]);
            matrix[i][j]=-1;
            if(j+1<n && matrix[i][j+1]!=-1){
                q.push({i,j+1});
            }
            if(i+1<n && matrix[i+1][j]!=-1){
                q.push({i+1,j});
            }
            
        }
        return ans;
    }
};