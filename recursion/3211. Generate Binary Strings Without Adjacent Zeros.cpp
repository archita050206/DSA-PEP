#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    void solver(int i, string &temp, vector<string>&ans, int n){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        if((i == 0)|| (i>0) && temp.back()!='0'){
            temp.push_back('0');
            solver(i+1,temp,ans,n);
            temp.pop_back();
        }
        temp.push_back('1');
        solver(i+1,temp,ans,n);
        temp.pop_back();
    }
    vector<string> validStrings(int n) {
        string temp="";
        vector<string>ans;
        solver(0,temp,ans,n);
        return ans;
    }
};