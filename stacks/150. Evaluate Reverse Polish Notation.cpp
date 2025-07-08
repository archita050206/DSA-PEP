#include<stack>
#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int num1,num2;
        for(string c: tokens){
            if(c=="*" || c=="+" || c=="-" || c=="/"){
                num2=st.top();
                st.pop();
                num1=st.top();
                st.pop();
                if(c=="+"){
                    st.push(num1+num2);
                }
                else if(c=="-"){
                    st.push(num1-num2);
                }
                else if(c=="/"){
                    if(num2==0)return 0;
                    st.push(num1/num2);
                }
                else if(c=="*"){
                    st.push(num1*num2);
                }
            }
            else st.push(stoi(c));
        }
        return st.top();
    }
};