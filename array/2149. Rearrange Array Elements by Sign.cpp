#include <vector>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos,neg;
        for(int i: nums){
            if(i<0){
                neg.push_back(i);
            }
            else pos.push_back(i);
        }
        int j=0,k=0,n1=pos.size(), n2=neg.size();
        if(n1==0 || n2==0)return vector<int>{};
        for(int i=0;i<nums.size();i++){
            if((i%2)==0){
                nums[i]=pos[j];
                j++;
            }
            else{
                nums[i]=neg[k];
                k++;
            }
        }
        return nums;
    }
};