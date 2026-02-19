#include<stack>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>ans;
        int n=nums2.size();
        st.push(nums2[n-1]);
        unordered_map<int,int>mp;
        mp[nums2[n-1]]=-1;
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i])st.pop();
            if(st.empty()){
                st.push(nums2[i]);
                mp[nums2[i]]=-1;
            }
            else {
                mp[nums2[i]]=st.top();
                st.push(nums2[i]);
            }
        }
        for(int i: nums1){
            ans.push_back(mp[i]);
        }
        return ans;

    }
};