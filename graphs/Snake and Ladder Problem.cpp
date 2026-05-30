// User function Template for C++

class Solution {
  public:
    int minThrow(int N, int arr[]) {
        // code here
        vector<int>board(31,-1);
        for(int i=0;i<2*N;i+=2){
            board[arr[i]]=arr[i+1];
        }
        vector<bool>visited(31,false);
        queue<pair<int,int>>q;
        q.push({1,0});//node, steps
        visited[1]=true;
        while(!q.empty()){
            int node=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(node==30)return steps;
            
            for(int d=1;d<=6;d++){
                int nextNode=node+d;
                if(nextNode>=31)continue;
                if(board[nextNode]!=-1)nextNode=board[nextNode];
                if(!visited[nextNode]){
                    visited[nextNode]=true;
                    q.push({nextNode, steps+1});
                }
            }
        }
        return -1;
    }
};