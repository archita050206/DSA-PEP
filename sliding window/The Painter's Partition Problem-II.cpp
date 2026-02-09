#include<vector>
#include<algorithm>
using namespace std;
class Solution {
  public:
    bool check(vector<int>&arr, int m, int k){
        int sum=0,cnt=1;
        for(int i: arr){
            if(sum+i>m){
                cnt++;
                sum=i;
            }
            else sum+=i;
        }
        return (cnt<=k)?true:false;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int l=*max_element(arr.begin(),arr.end());
        int s=0;
        for(int i: arr){
            s+=i;
        }
        int h=s,ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            bool b=check(arr,mid,k);
            if(b){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};