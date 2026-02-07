#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        vector<int>nums;
        for(int i=1;i<=n;i++){
            n=n-i;
            if(n<0){
                nums.push_back(abs(n));
                break;
            }
            else nums.push_back(i);
        }
        int l=0, h=nums.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]!=mid+1){
                h=mid-1;

            }
            else l=mid+1;
        }
        return l;

    }
};