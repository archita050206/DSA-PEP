#include<iostream>
#include<stack>
using namespace std;
class Solution {
  public:
    int precedence(char c){
        if(c=='^')return 3;
        else if(c=='/' || c=='*')return 2;
        else if(c=='+'||c=='-')return 1;
        return -1;
    }
    bool isRightAssociative(char c){
        return c=='^';
    }
    string infixToPostfix(string& s) {
        // code here
        string ans="";
        stack<char>st;
        for(char c: s){
            if((c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0'&&c<='9'))ans+=c;
            else if(c=='('){
                st.push(c);
                
            }
            else if(c==')'){
                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
                
            }
            else{
                while(!st.empty() && st.top()!='(' &&
                (precedence(st.top())>precedence(c) || precedence(st.top())==precedence(c) && !isRightAssociative(c))){
                    ans+=st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
