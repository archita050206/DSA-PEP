#include<stack>
#include<algorithm>
#include<string>

using namespace std;
class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        for(char c: s){
            if(isdigit(c) && isalpha(st.top())){
                st.pop();
            }
            else st.push(c);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        // string ans="";
        // for(char c: s){
        //     if(isdigit(c) && isalpha(ans.back())){
        //         ans.pop_back();
        //     }
        //     else ans+=c;
        // }
        // return ans;
    }
};