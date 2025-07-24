#include <vector>
#include <queue>

using namespace std;
class Solution {
public:

    void dfs(int node, vector<vector<int>>& rooms, vector<bool>&visited){
        
        visited[node]=true;
        for(int neighbour: rooms[node]){
            if(!visited[neighbour])
            dfs(neighbour,rooms,visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>visited(rooms.size(),false);
        dfs(0,rooms,visited);
        for(bool b: visited){
            if(!b)return false;
        }
        return true;
    }
};