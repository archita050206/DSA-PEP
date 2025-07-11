#include<vector>
#include<string>
#include<algorithm>

using namespace std;
class Solution {
public:

    bool isPalindrome(string str){
        if(str.empty())return false;
        int n=str.size();
        for(int i=0;i<n/2;i++){
            if(str[i]!=str[n-i-1])return false;
        }
        return true;
    }

    void solver(string s, vector<string>&temp, vector<vector<string>>&ans){
        if(s.size()==0){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<s.size();i++){
            string lpart=s.substr(0,i+1);
            if(isPalindrome(lpart)){
                temp.push_back(lpart);
                string rpart=s.substr(i+1);
                solver(rpart,temp,ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string>temp;
        vector<vector<string>>ans;
        solver(s,temp,ans);
        return ans;
    }
};