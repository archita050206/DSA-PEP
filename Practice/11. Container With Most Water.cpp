#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        if(n==1){
            return 0;
        }
        int maxi=0;
        int i=0,j=n-1;
        while(i<j){
            int area=(min(height[i], height[j]))*(j-i);
            maxi=max(maxi,area);
            if(height[i]<=height[j])i++;
            else j--;
        }
        return maxi;
    }
};