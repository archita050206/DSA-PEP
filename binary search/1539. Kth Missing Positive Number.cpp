#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=0,n=arr.size(),h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int diff=arr[mid]-(mid+1);
            if(diff<k){
                l=mid+1;
            }
            else h=mid-1;

        }
        return l+k;
    }
};