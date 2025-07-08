#include<stack>
#include<vector>

using namespace std;
class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        stack<int>st;
        int n=arr.size();
        vector<int>ans(n,-1);
        for(int i=n-1;i>=0;i--){
             while(!st.empty() && arr[i]>=st.top())st.pop();
             if(!st.empty() && arr[i]<st.top()){
                ans[i]=st.top();
                
            }
            st.push(arr[i]);
           
        }
        return ans;
    }
};