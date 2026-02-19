#include<stack>
#include<vector>

using namespace std;
class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n=arr.size();
        stack<int>st;
        st.push(arr[n-1]);
        vector<int>nse(n,-1);
        for(int i=(n-2);i>=0;i--){
            while(!st.empty() && st.top()>=arr[i])st.pop();
            if(!st.empty())nse[i]=st.top();
            st.push(arr[i]);
        }
        return nse;
    }
};