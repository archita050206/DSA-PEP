#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
vector<int>parent,rank;
    int find(int node){
        if(parent[node]!=node){
            parent[node]=find(parent[node]);
        }
        return parent[node];
    }
    void unionByRank(int x, int y){
        int rootx=find(x);
        int rooty=find(y);
        if(rootx==rooty)return;
        if(rank[rootx]==rank[rooty]){
            parent[rooty]=rootx;
            rank[rootx]++;
        }
        else if(rank[rootx]<rank[rooty]){
            parent[rootx]=rooty;
        }
        else parent[rooty]=rootx;
    }
    int largestComponentSize(vector<int>& nums) {
        
        
        int maxVal=*max_element(nums.begin(), nums.end());
        parent.resize(maxVal+1);
        rank.resize(maxVal+1,0);
        for(int i=0;i<=maxVal;i++){
            parent[i]=i;
        }
        unordered_map<int,int>mp;
        for(int num: nums){
            for(int f=2;f*f<=num;f++){
                if(num%f==0){
                    if(!mp.count(f))mp[f]=num;
                    else{
                        unionByRank(num,mp[f]);
                    }
                    int other=num/f;
                    if(!mp.count(other))mp[other]=num;
                    else unionByRank(num,mp[other]);
                }
                
            }
            if(!mp.count(num))mp[num]=num;
            else unionByRank(num,mp[num]);
        }
        unordered_map<int,int>components;
        int maxi=0;
        for(int num: nums){
            int x=find(num);
            components[x]++;
            maxi=max(maxi, components[x]);
        }
        return maxi;
    
    }
};