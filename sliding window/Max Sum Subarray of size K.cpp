#include<vector>
#include<algorithm>
using namespace std;
/* 

 TC= O(n)
 SC= O(1)

 -> keep increasing j and find sum till we reach the window size k
 -> once reached, remove the ith val and add the jth val, incremented

 -> Kadane's algorithm: maximum subarray sum-> no size limit, no sum limit
 -> Subarray sum equals k: find number of subarrays having sum k-> no size limit, sum limit
 -> sliding window: size limit find sum/ sum limit find size

*/


class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        // code here
        int i=0,j=0,sum=0,ans=-1;
        int n=arr.size();
        if(k>n){
            return -1;
        }
        while(j<n){
            sum+=arr[j];
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                ans=max(ans,sum);
                sum-=arr[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};