#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==key){
                int mini=(i-k)>=0?(i-k):0;
                int maxi=(i+k)<n?(i+k):n-1;
                for(int k=mini;k<=maxi;k++)st.insert(k);
            }
        }
        vector<int>ans(st.begin(), st.end());
        return ans;
    }
};