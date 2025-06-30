#include<vector>
#include<string>

using namespace std;
class Solution {
public:

void solve(int n,string str, int open, int close, vector<string>&ans){
    if(str.length()== 2*n){
        ans.push_back(str);
        return;
    }
    if(open<n){
        solve(n,str+'(',open+ 1,close,ans);
    }
    if(close<open){
        solve(n, str+')',open, close+1, ans);
    }
}

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string str="";
        solve(n,str,0,0,ans);
        return ans;
    }
};