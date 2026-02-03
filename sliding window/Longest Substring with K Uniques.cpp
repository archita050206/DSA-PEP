#include<string>
#include<unordered_map>
using namespace std;
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<char,int>mp;
        int i=0,j=0,n=s.length(),maxi=-1;
        while(j<n){
            mp[s[j]]++;
            if(mp.size()==k){
                maxi=max(maxi,j-i+1);
                
            }
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                
                i++;
                
            }
            j++;
        }
        return maxi;
    }
};