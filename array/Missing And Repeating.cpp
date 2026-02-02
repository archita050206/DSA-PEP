
#include <vector>
#include<algorithm>
#include<climits>
using namespace std;class Solution {

  public:
    vector<int> findTwoElement(vector<int>& nums) {
        // code here
        int repeating=-1, missing=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int idx=abs(nums[i])-1;
            if(nums[idx]>0){
                nums[idx]=-nums[idx];
            }
            else{
                repeating = abs(nums[i]);
                
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                missing=i+1;
                break;
            }
        }
        return vector<int>{repeating,missing};
    }
};