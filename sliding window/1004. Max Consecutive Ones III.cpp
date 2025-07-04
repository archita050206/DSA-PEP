#include<vector>
#include<algorithm>
using namespace std;
/*
problem-> find longest substring with atmost k 0's, donot need a map as i only need to keep count of 0s and not other elements
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size(),len=-1;
        int cnt=0;
        while(j<n){
            if(nums[j]==0)cnt++;
            while(cnt>k){
                if(nums[i]==0)cnt--;
                i++;
            }
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};