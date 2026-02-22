#include<stack>
#include<vector>
#include<string>
#include<climits>
using namespace std;
class Solution {
public:
    vector<int>nextSE(vector<int>&arr,int n){
        vector<int>ans(n,n);
        stack<int>st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty())ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>prevSE(vector<int>&arr,int n){
        vector<int>ans(n,-1);
        stack<int>st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            if(!st.empty())ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>pse=prevSE(heights,n);
        vector<int>nse=nextSE(heights,n);
        int maxi=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int area=(nse[i]-pse[i]-1)*heights[i];
            maxi=max(maxi,area);
        }
        return maxi;
    }
};