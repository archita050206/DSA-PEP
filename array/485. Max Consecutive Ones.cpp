#include<vector>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,j=0,len=0,maxi=0;
        int n=nums.size();
        while(j<n){
            if(nums[j]==1){
                //len=max(len,j-i+1);
                len++;
                maxi=max(maxi,len);
            }
            else{
                 //i=j+1;
                 len=0;
            } 
            j++;
        }
        return maxi;
    }
};