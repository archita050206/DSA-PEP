#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>ans;
        if(s.size()<p.size())return ans;
        vector<int>pc(26,0), sc(26,0);
        for(int i=0;i<p.size();i++){
            pc[p[i]-'a']++;
            sc[s[i]-'a']++;
        }
        if(sc==pc)ans.push_back(0);
        for(int i=p.size();i<s.size();i++){
            sc[s[i]-'a']++;
            sc[s[i-p.size()]-'a']--;
            if(sc==pc)ans.push_back(i-p.size()+1);
        }
        return ans;
    }
};