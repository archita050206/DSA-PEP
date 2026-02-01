#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2, j=n-1;
        // starting from the last, finding the first strictly smaller element (nums[i]<nums[i+1])
        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }
        // staring from i, finding the first strictly greater element (nums[j]>nums[i]) and then swapping the 2
        if(i>=0){
            while(j>=0 && nums[j]<=nums[i])j--;
            swap(nums[i], nums[j]);
        }
        //swapping from the (i+1)th index to the end
        reverse(nums.begin()+i+1, nums.end());
    }
};