#include<stack>
#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(string s: operations){
            if(s=="+"){
                int num2=st.top();
                st.pop();
                int num1=st.top();
                int ans=num1+num2;
                st.push(num2);
                st.push(ans);
            }
            else if(s=="D"){
                int n1=st.top();
                st.push(n1*2);
            }
            else if(s=="C")st.pop();
            else st.push(stoi(s));
        }
        int sum=0;
        while(!st.empty()){
            int x=st.top();
            st.pop();
            sum+=x;
        }
        return sum;
    }
};