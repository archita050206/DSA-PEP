#include<vector>
#include<set>
using namespace std;

// try using bitwise operation to create subsets

class Solution {
public:
bool solver(int idx, long long pro1, long long pro2,vector<int>&nums, long long target){
    if(pro1>target || pro2>target)return false;
    if(idx==nums.size())return (pro1==target && pro2==target);
    bool a=solver(idx+1,pro1*nums[idx],pro2,nums,target);
    bool b=solver(idx+1,pro1,pro2*nums[idx],nums,target);
    return a||b;
}
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        // unsigned long long pro=1;
        // for(int i: nums){
        //     pro*=i;
        // }
        // if((pro%target==0) && (pro/target==target))return true;
        // return false;
        int idx=0;
        long long pro1=1, pro2=1;
        return solver(idx,pro1,pro2,nums,target);
    }
};