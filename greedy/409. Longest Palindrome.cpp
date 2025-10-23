#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(char c: s){
            mp[c]++;

        }
        int len=0;
        bool b=false;
        for(auto p: mp){
            len+=p.second/2;
            if(p.second%2==1)b=true;
        }
        len=len*2;
        if(b)len+=1;
        return len;
    }
};