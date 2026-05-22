// User function Template for C++
#include<vector>
#include<unordered_map>

using namespace std;
class Solution {
  public:
    int eulerPath(int N, vector<vector<int>> graph) {
        // code here
        unordered_map<int,int>mp;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(graph[i][j]==1){
                    mp[i]++;
                }
            }
        }
        int odd=0;
        for(auto &p: mp){
            if(p.second%2!=0){
                odd++;
            }
        }
        return (odd==2 || odd==0)?1:0;
    }
};