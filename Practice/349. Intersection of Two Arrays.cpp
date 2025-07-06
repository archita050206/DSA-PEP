#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // unordered_set<int>st(nums1.begin(),nums1.end());
        // vector<int>ans;
        // for(int i:nums2){
        //     if(st.count(i))
        //     {ans.push_back(i);
        //     st.erase(i);
        //     }
        // }
        // return ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        unordered_set<int>ans;
        int i=0;
        int j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                ans.insert(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else j++;
        }
        vector<int>v(ans.begin(),ans.end());
        return v;
    }
};