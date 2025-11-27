#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
  public:
    void solver(int i, int j, string &temp, vector<string>&ans, int n,vector<vector<int>>& maze){
        if(i<0 || j<0 || i>=n || j>=n || maze[i][j]==0)return;
        if(i==(n-1) && j==(n-1)){
            ans.push_back(temp);
        }
        maze[i][j]=0;
        temp.push_back('D');
        solver(i+1,j,temp,ans,n,maze);
        temp.pop_back();
        temp.push_back('U');
        solver(i-1,j,temp,ans,n,maze);
        temp.pop_back();
        temp.push_back('R');
        solver(i,j+1,temp,ans,n,maze);
        temp.pop_back();
        temp.push_back('L');
        solver(i,j-1,temp,ans,n,maze);
        temp.pop_back();
        maze[i][j]=1;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string>ans;
        string temp="";
        solver(0,0,temp,ans,maze.size(),maze);
        sort(ans.begin(),ans.end());
        return ans;
    }
};