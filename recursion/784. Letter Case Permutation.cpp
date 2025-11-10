#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    void solver(int i, string &s, vector<string>&ans){
        if(i==s.length()){
            ans.push_back(s);
            return;
        }
        if(isalpha(s[i])){
            s[i]=tolower(s[i]);
            solver(i+1,s,ans);
            s[i]=toupper(s[i]);
            solver(i+1,s,ans);
        }
        else{
            solver(i+1,s,ans);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        solver(0,s,ans);
        return ans;
    }
};