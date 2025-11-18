#include<vector>
using namespace std;
class Solution {
public:
    int solver(int l, int h, vector<int>&nums){
        if(l==h)return nums[l];
        int takeLeft=nums[l]-solver(l+1,h,nums);
        int takeRight=nums[h]-solver(l,h-1,nums);
        return max(takeLeft,takeRight);
    }
    bool predictTheWinner(vector<int>& nums) {
        return solver(0,nums.size()-1,nums)>=0;
    }
};