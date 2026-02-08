#include<vector>
#include<cmath>
using namespace std;
class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        int l=0, h=m;
        while(l<=h){
            int mid=l+(h-l)/2;
            int calc=pow(mid,n);
            if(calc==m)return mid;
            
            else if(calc<m)l=mid+1;
            else h=mid-1;
            
        }
        return -1;
    }
};