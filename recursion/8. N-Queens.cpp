#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
bool isSafe(int row, int col,vector<string>&board,int n){
    for(int i=0;i<n;i++){
        if(board[row][i]=='Q')return false;
        if(board[i][col]=='Q')return false;
    }
    for(int i=row,j=col;i>=0 && j>=0; i--,j--){
        if(board[i][j]=='Q')return false;
    }
    for(int i=row,j=col;i>=0 && j<n;i--, j++){
        if(board[i][j]=='Q')return false;
    }
    return true;
}
    void solver(int i, vector<string>&board,vector<vector<string>>&ans, int n ){
        if(i==n){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(i,j,board,n)){
                board[i][j]='Q';
                solver(i+1,board,ans,n);
                board[i][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
        solver(0,board,ans,n);
        return ans;
    }
};