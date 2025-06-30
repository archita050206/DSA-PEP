#include<stack>
#include<string>
using namespace std;

// TC= O(n)
// SC= O(n)
// if stack is empty, push '(' and dont add to string, otherwise pop from stack and if stack doesnot become empty then add to string


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