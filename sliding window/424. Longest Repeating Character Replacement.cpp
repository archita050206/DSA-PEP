#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool search( unordered_map<char,int>&mp, int k){
      
        for(auto &p: mp){
            if(p.second==k){
                return true;
            }
        }
        return false;
    }
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int i=0,j=0,len=0,maxFreq=0;
        while(j<s.length()){
            mp[s[j]]++;
            // if(mp.size()>=2){
            //     while(!search(mp,k)){
            //         mp[s[i]]--;
            //         if(mp[s[i]]==0)mp.erase(s[i]);
            //         i++;
            //     }
            // }
            maxFreq=max(maxFreq, mp[s[j]]);
            while((j-i+1)-maxFreq>k){
                mp[s[i]]--;
                i++;
            }
            len=max(len,j-i+1);

            j++;

        }
        return len;
    }
};