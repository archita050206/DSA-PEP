#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        //flatten first
        vector<int>nodes(1);
        bool ltr=true;
        for(int i=n-1;i>=0;i--){
            if(ltr){
                for(int j=0;j<n;j++){
                    nodes.push_back(board[i][j]);
                }
            }
            else{
                for(int j=n-1;j>=0;j--){
                    nodes.push_back(board[i][j]);
                }
            }
            ltr=!ltr;
        }
        vector<int>visited(n*n+1,false);
        queue<pair<int,int>>q;//node, count
        visited[1]=true;
        q.push({1,0});
        while(!q.empty()){
            int node=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(node==n*n)return steps;
            
            for(int i=1;i<=6;i++){
                int newNode=node+i;
                if(newNode>n*n)continue;
                if(nodes[newNode]!=-1){
                    newNode=nodes[newNode];
                }
                if(!visited[newNode]){
                    visited[newNode]=true;
                    q.push({newNode,steps+1});
                }
            }
        }
        return -1;
    }
};