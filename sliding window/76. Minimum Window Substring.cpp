#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int i=0,j=0,formed=0,start=-1;
        unordered_map<char,int>sm,tm;
        for(char c: t){
            tm[c]++;
        }
        int required=tm.size(),len=INT_MAX;
        while(j<s.length()){
            char c=s[j];
            sm[c]++;
            if(tm.count(c) && sm[c]==tm[c])formed++;
            while(i<=j && formed==required){
                if(len>j-i+1){
                len=min(len,j-i+1);
                start=i;
                }
                sm[s[i]]--;
                if(tm.count(s[i]) && sm[s[i]]<tm[s[i]]){
                    formed--;
                }
                i++;
            }
            j++;
        }
        return start==-1?"":s.substr(start,len);
    }
};