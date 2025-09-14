#include<unordered_map>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        
        unordered_map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        
        priority_queue<pair<int,char>>pq;
        for(auto p:mp){
            if(p.second>(n+1)/2)return "";
            pq.push({p.second, p.first});

        }
        string ans="";
        pair<int,char>prev={0,'#'};
        while(!pq.empty()){
            int count=pq.top().first;
            char c=pq.top().second;
            pq.pop();
            ans+=c;
            if(prev.first>0)pq.push(prev);
            count--;
            prev={count,c};
        }
        return ans;
    }
};