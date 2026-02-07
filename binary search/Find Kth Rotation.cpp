#include<vector>
using namespace std;
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int l=0,n=arr.size(),h=n-1;
        while(l<h){
            int mid=l+(h-l)/2;
            if(arr[mid]>arr[h]){
                l=mid+1;
            }
            else h=mid;
        }
        return h;
        
    }
};
