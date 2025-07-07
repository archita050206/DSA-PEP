#include<stack>
#include<algorithm>
#include<string>

using namespace std;
class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(char c: s){
            if(!st.empty() && ((st.top()-32==c) ||(st.top()+32==c))){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        // string ans="";
        // for(char c: s){
        //     if(!ans.empty() && ((ans.back()+32==c)||(ans.back()-32==c))){
        //         ans.pop_back();
        //     }
        //     else{
        //         ans+=c;
        //     }
        // }
        // return ans;
    }
};