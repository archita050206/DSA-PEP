#include<stack>
#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>st;
        for(string str: logs){
            if(str=="../"){
                if(!st.empty())st.pop();
            }
            else if(str!="./"){
                st.push(str);
            }
             

        }
        return st.size();
    }
};