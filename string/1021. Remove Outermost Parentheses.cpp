#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
    
    string str="";
    stack<char>st;
    for(char c:s){
    
        if(c=='('){
            if(st.empty())st.push(c);
            else{
                st.push(c);
                str+=c;
            }
        }
        else if(c==')'){
            if(st.top()=='('){
               st.pop();
               if(!st.empty())
                str+=c;
            }
           
        }


    }
    return str;
    }
};