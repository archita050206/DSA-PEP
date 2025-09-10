// User function Template for C++
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
  public:
    int distinct(vector<vector<int>> M, int N) {
        // code here
        unordered_map<int,int>mp;
        for(int i=0;i<N;i++){
            unordered_set<int>st;
            for(int j=0;j<N;j++){
                st.insert(M[i][j]);
            }
            for(int val:st){
                mp[val]++;
            }
        }
        int cnt=0;
        for(auto &p:mp){
            if(p.second==N)cnt++;
        }
        return cnt;
    }
};