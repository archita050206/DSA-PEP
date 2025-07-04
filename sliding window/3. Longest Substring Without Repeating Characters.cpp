#include<climits>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int n=s.length();
        map<char,bool>mp;
        int len=0;
        while(j<n){
            if(!mp[s[j]]){
                mp[s[j]]=true;
                len=max(len,j-i+1);
                j++;
            }
            else if(mp[s[j]]){
                mp[s[i]]=false;
                i++;
            }
        }
        return len;
    }
};