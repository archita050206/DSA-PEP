#include<iomanip>
#include<vector>
#include<climits>
using namespace std;

// Kadane's algorithm: Find the maximum prod in the forward direction, then in the backward direction
// TC= O(n)
// SC= O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN;
        int pro=1,pro1=1;
        for(int i:nums){
            pro*=i;
            maxi=max(maxi,pro);
            if(pro==0)pro=1;
        }
        for(int i=nums.size()-1;i>0;i--){
            pro1*=nums[i];
            maxi=max(maxi,pro1);
            if(pro1==0)pro1=1;
        }
        return maxi;
    }
};