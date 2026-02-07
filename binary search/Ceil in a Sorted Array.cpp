// User function Template for C++
#include<vector>
using namespace std;
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int l=0,n=arr.size(),h=n-1,ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(arr[mid]>=x){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};