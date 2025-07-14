#include<vector>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a=0,b=0;
        long long x=0;
        for(int i=0;i<nums.size();i++){ // get XOR of all numbers
            x^=nums[i];
        }
        long long diff=x & (-x);// get 2's complement, gives the position of the right most set bit
        for(int num: nums){
            if(diff&num){
                a^=num; // if the & is not 0 then add in first
            }
            else{
                b^=num;// if and & is zero then add in this 
            }
        }
        return {a,b};
    }
};