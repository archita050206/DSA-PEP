#include<vector>
using namespace std;
class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig){
        for(int i=0;i<9;i++){
            if(board[row][i]==dig)return false;
            if(board[i][col]==dig)return false;
        }
        int sr=(row/3)*3;
        int sc=(col/3)*3;
        for(int i=sr;i<=sr+2;i++){
            for(int j=sc;j<=sc+2;j++){
                if(board[i][j]==dig)return false;
            }
        }
        return true;

    }
    bool solver(vector<vector<char>>& board, int row, int col){
        if(row==9)return true;
        if(col==9){
            return solver(board,row+1,0);
        }
        if(board[row][col]!='.')return solver(board,row,col+1);
        for(char i='1';i<='9';i++){
            if(isSafe(board,row,col,i)){
                board[row][col]=i;
                if(solver(board,row,col+1))return true;
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solver(board,0,0);
    }
};