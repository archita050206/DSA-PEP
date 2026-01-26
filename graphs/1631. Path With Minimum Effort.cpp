#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n, vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,  pair<int,int>>>>pq;
        pq.push({0, {0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            int cost=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(i==(n-1) && j==(m-1))return dist[i][j];
            if(cost>dist[i][j])continue;
            if((i-1)>=0){
                int newCost= max(cost, abs(heights[i][j]-heights[i-1][j]));
                if(newCost<dist[i-1][j]){
                    dist[i-1][j]=newCost;
                    pq.push({newCost, {i-1,j}});
                }
            }
            if((j-1)>=0){
                int newCost= max(cost, abs(heights[i][j]-heights[i][j-1]));
                if(newCost<dist[i][j-1]){
                    dist[i][j-1]=newCost;
                    pq.push({newCost, {i,j-1}});
                }
            }
            if((i+1)<n){
                int newCost= max(cost, abs(heights[i][j]-heights[i+1][j]));
                if(newCost<dist[i+1][j]){
                    dist[i+1][j]=newCost;
                    pq.push({newCost, {i+1,j}});
                }
            }
            if((j+1)<m){
                int newCost= max(cost, abs(heights[i][j]-heights[i][j+1]));
                if(newCost<dist[i][j+1]){
                    dist[i][j+1]=newCost;
                    pq.push({newCost, {i,j+1}});
                }
            }
        }
        return -1;
    }
};