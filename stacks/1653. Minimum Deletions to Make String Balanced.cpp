#include<stack>
#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int cnt=0;
       for(char c: s){
        if(!st.empty() && (st.top()=='b' && c=='a')){
            st.pop();
            cnt++;
        }
        else st.push(c);
       }
       return cnt;
    // int cnt=0;
    // string ans="";
    // for(char c: s){
    //     if(!ans.empty() && (ans.back()=='b' && c=='a'))
    //     {ans.pop_back();
    //     cnt++;
    //     }
    //     else ans+=c;
    // }
    // return cnt;
    }
};