#include <vector>
using namespace std;

// slightly modified: array contains repeating elements so always return the smallest index

class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        // code here
        int l=0;
        int r=arr.size()-1;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]==k){
                ans=mid;
                r=mid-1;
            }
            else if(arr[mid]<k)l=mid+1;
            else r=mid-1;
        }
        return ans;
    }
};