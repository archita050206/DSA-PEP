#include <vector>
using namespace std;
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        // vector<int>v;
        int n=nums.size();
        // for(int i=0;i<(n-k+1);i++){
        //     bool flag=false;
        //     for(int j=1;j<k;j++){
        //         if(nums[i+(j-1)]>=nums[i+j]){
        //             flag=true;
        //             break;
        //         }
        //     }
        //     if(!flag)v.push_back(i);
        // }
        // for(int i = 1; i < v.size() ; i++){
        //     if(v[i] - v[i-1] == k) return true;
        // }
        // if(n < 2*k) return false;
        // return false;
        vector<int>v(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i])v[i]=v[i-1]+1;
        }
        for(int i=0;i<=(n-2*k);i++){
            if(v[i+k-1]>=k && v[i+2*k-1]>=k)return true;
        }
        return false;
    }
};