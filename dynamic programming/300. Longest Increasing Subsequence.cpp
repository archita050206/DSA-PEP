#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solver(int i, int prev, vector<int>&nums, vector<vector<int>>&dp){
        if(i==nums.size())return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int skip=solver(i+1,prev,nums,dp);
        int take=0;
        if(prev==-1|| nums[prev]<nums[i]){
            take=1+solver(i+1,i,nums,dp);
        }
        return dp[i][prev+1]=max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        // vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        // return solver(0,-1,nums,dp);
        vector<int>temp;
        for(int i: nums){
            auto it=lower_bound(temp.begin(),temp.end(),i);//--> give the values form the array >=i
            if(it==temp.end()){//--> if it reaches end, then there is no value, add the ele
                temp.push_back(i);
            }
            else *it=i;//--> this iterator updates the value acc

        }
        return temp.size();
    }
};