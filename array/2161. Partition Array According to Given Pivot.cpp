#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int i=0,n=nums.size(),j=n-1;
        vector<int>ans(n);
        for(int k=0;k<n;k++){
            if(nums[k]<pivot){
                ans[i]=nums[k];
                i++;
            }
           
        }
        for(int k=n-1;k>=0;k--){
             if(nums[k]>pivot){
                ans[j]=nums[k];
                j--;
            }
        }
        if(i>j)return ans;
        for(int k=i;k<=j;k++){
            ans[k]=pivot;
        }
        return ans;
    }
};