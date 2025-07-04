#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

/*
Bruteforce
-> sort, use for loop, continue/skip for duplicate elements, reset count and print the maximum among length and count 
-> at last we again do max because what if the cnt keeps increasing but the length does not get ipdated as the else condition is not reached
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        else if(nums.size()==1)return 1;
        sort(nums.begin(), nums.end());
        int cnt=1,len=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1])continue;

            if(nums[i+1]-1==nums[i])cnt++;
            else{
                len=max(len,cnt);
                cnt=1;
            }
        }
        len = max(len, cnt); 
        return len;
    }
};