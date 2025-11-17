#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool solver(int i, int j, int n,int m, int k, string &word, vector<vector<char>>& board){
        if(i<0||i>=n ||j<0||j>=m|| board[i][j]!=word[k])return false;
        if(k==word.length()-1)return true;
        char c=board[i][j];
        board[i][j]='#';
        bool op1=solver(i+1,j,n,m,k+1,word,board);
         bool op2=solver(i,j+1,n,m,k+1,word,board);
          bool op3=solver(i-1,j,n,m,k+1,word,board);
           bool op4=solver(i,j-1,n,m,k+1,word,board);
           board[i][j]=c;
           return op1||op2||op3||op4;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                   if( solver(i,j,n,m,0,word,board))return true;
                }
            }
        }
        return false;
    }
};