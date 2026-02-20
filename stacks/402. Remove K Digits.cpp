#include<stack>
#include<algorithm>
#include<string>

using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0;i<num.size();i++){
            char c=num[i];
            while(!st.empty() && k>0 && st.top()>c){
                st.pop();

                k--;
            }
            st.push(c);
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        if(st.empty())return "0";
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int idx=0;
        while(idx<ans.size() && ans[idx]=='0'){
           idx++;
        }
        ans=ans.substr(idx);
        return ans.empty()?"0":ans;
    }
};