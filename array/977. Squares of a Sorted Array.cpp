#include<iomanip>
#include<vector>
using namespace std;

/*
sorting in linear time complexity: O(n) using 2 pointer approach
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        vector<int>ans;
        while(i<=j){
            int sq1=nums[i]*nums[i];
            int sq2=nums[j]*nums[j];
            if(sq1>=sq2){
                ans.push_back(sq1);
                i++;

            }
            else{
                ans.push_back(sq2);
                j--;
            }
        }
        int n=ans.size();
        for(int i=0;i<n/2;i++){
            //swap(ans[i], ans[n-i-1]);
            int t=ans[i];
            ans[i]=ans[n-i-1];
            ans[n-i-1]=t;
        }
        return ans;

        
    }
};