#include<stack>
#include<algorithm>
#include<string>

using namespace std;
class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(char c:s){
            if(!st.empty() && ((c=='B' && st.top()=='A') || (c=='D' && st.top()=='C'))){
                st.pop();
            }
            else st.push(c);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans.length();

        // string ans="";
        // for(char c: s){
        //     if(!ans.empty() &&((c=='B' && ans.back()=='A') ||(c=='D' && ans.back()=='C') )){
        //         ans.pop_back();

        //     }
        //     else ans+=c;
        // }
        // return ans.length();
    }
};