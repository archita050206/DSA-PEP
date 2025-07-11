#include<vector>
#include<string>
#include<map>

using namespace std;
class Solution {
public:

    void solver(int idx, string digits,string &temp,  map<char,string>&mp, vector<string>&ans){
        if(idx>=digits.length()){
            ans.push_back(temp);
            return;
        }
        char c=digits[idx];
        string alpha=mp[c];
        for(int i=0;i<alpha.length();i++){
            temp.push_back(alpha[i]);
            solver(idx+1,digits,temp,mp,ans);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        int idx=0;
        string temp="";
        vector<string>ans;
        if(digits.length()==0)return ans;
        solver(idx,digits,temp,mp, ans);
        return ans;
    }
};