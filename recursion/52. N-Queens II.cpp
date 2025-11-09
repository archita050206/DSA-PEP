#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isSafe(int row, int col, vector<string>&board, int n){
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q')return false;
            if(board[row][i]=='Q')return false;
        }
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q')return false;
        }
        for(int i=row,j=col;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q')return false;
        }
        return true;
    }
    void solver(int row, vector<string>&board, int &ans, int n){
        if(row==n){
            ans++;
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(row,i,board,n)){
                board[row][i]='Q';
                solver(row+1,board,ans,n);
                board[row][i]='.';
            }
        }
    }
    int totalNQueens(int n) {
        int ans=0;
        vector<string>board(n,string(n,'.'));
        solver(0,board,ans,n);
        return ans;
    }
};