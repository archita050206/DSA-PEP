#include<stack>
#include<queue>
using namespace std;
class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        stack<int>st1,st2,st;
        int n=q.size();
        for(int i=0;i<(n/2);i++){
            int v=q.front();
            q.pop();
            st1.push(v);
        }
        while(!q.empty()){
            int v=q.front();
            q.pop();
            st2.push(v);
        }
        while(!st2.empty() && !st1.empty()){
            st.push(st2.top());
            st.push(st1.top());
            st2.pop();
            st1.pop();
            
        }
        if(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
        if(!st1.empty()){
            st.push(st1.top());
            st1.pop();
        }
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
    }
};