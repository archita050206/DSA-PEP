#include<vector>
#include<cfloat>
using namespace std;
class Solution {
  public:
    int least_average(vector<int> nums, int k) {
        // Code here
        int i=0,j=0,n=nums.size(),sum=0,idx=-1;
        double avg=DBL_MAX;
        while(j<n){
            sum+=nums[j];
            if((j-i+1==k)){
                double d=(double)sum/k;
                if(d<avg){
                    avg=d;
                    idx=i;
                }
                
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return idx+1;
    }
};