#include<climits>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int i=0,j=0,len=0;
        int n=str.length();
        unordered_map<char,bool>mp;
        while(j<n){
            while(mp[str[j]]){
                mp[str[i]]=false;
                i++;
            }
            mp[str[j]]=true;
            len=max(len, j-i+1);
            j++;
        }
        return len;
    }
    
};