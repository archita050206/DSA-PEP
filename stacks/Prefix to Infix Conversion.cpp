// User function Template for C++
#include<iostream>
#include<stack>
using namespace std;
class Solution {
  public:
    string preToInfix(string s) {
        // Write your code here
        int n=s.length();
        stack<string>st;
        for(int i=n-1;i>=0;i--){
            char c=s[i];
            if(c=='*'||c=='+'||c=='-'||c=='/'||c=='%'||c=='^'){
                string first=st.top();
                st.pop();
                string sec=st.top();
                st.pop();
                string res='('+first+c+sec+')';
                st.push(res);
            }
            else{
                st.push(string(1,c));
            }
            
        }
        return st.top();
        
    }
};