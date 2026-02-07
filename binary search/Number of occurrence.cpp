#include<vector>
#include<algorithm>
using namespace std;
class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int n=arr.size(),l=0,h=n-1,i=-1,j=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(arr[mid]==target){
                i=mid;
                h=mid-1;
            }
            else if(arr[mid]<target){
                l=mid+1;
            }
            else h=mid-1;
        }
        l=0,h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(arr[mid]==target){
                j=mid;
                l=mid+1;
            }
            else if(arr[mid]<target){
                l=mid+1;
            }
            else h=mid-1;
        }
        if(i==-1 && j==-1)return 0;
        return abs(i-j)+1;
    }
};
