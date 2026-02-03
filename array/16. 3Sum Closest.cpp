#include<vector>
#include<algorithm>
using namespace std;
class Solution {

    public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int closest=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n;i++){
            int k=i+1;
            int j=n-1;
            while(k<j){
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(sum-target)<abs(closest-target)){
                    closest=sum;
                }
                else if(sum<target)k++;
                else if(sum>target)j--;
                else if(sum==target)return sum;
            }

        }
        return closest;
    }
};