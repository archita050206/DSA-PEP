#include<string>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {

        // TC= O(n)
        // SC =O(n)

        // stack<char>st;
        // for(char c: s){
        //     if(c=='('){
        //         st.push(c);
        //     }
        //     else if( c==')'){
        //         if(!st.empty() && st.top()=='('  )st.pop();
        //         else st.push(c);
        //     }
        // }
        // return st.size();

        // TC= O(n)
        // SC =O(1)

        //count-> to nullify opened brackets and size-> to nullify closed brackets
        int size=0,count=0;
        for(char c: s){
            if(c=='('){
                size++;
            }
            if(c==')'){
                if(size>0)size--;
                else count++;
            }
        }
        return size+count;
    }
};