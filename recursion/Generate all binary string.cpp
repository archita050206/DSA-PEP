#include<vector>
#include<string>

using namespace std;

//push str into the array if i>=n, else first add 0 then after applying condition apply 1
class Solution {
  public:
    void solve(int i, string str, int num, vector<string>&ans){
        if(i>=num){
            ans.push_back(str);
            str="";
            return;
        }
        solve(i+1, str+"0", num, ans);
        if(str.empty() || str.back()!='1'){
            solve(i+1, str+"1", num, ans);
        }
    }
    
    vector<string> generateBinaryStrings(int num) {
        // Write your code
        vector<string>ans;
        string str="";
        solve(0,str,num,ans);
        return ans;
    }
};