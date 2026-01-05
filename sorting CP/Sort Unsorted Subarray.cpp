// User function template for C++
#include<vector>
#include<climits>
using namespace std;

class Solution {
  public:
    vector<int> printUnsorted(vector<int>& arr) {
        // Code here
        int n=arr.size();
        int i=0, j=n-1;
        for( i=0;i<n-1;i++)if(arr[i]>arr[i+1])break;
        if(i==(n-1))return {0,0};
        for( j=(n-1);j>0;j--)if(arr[j]<arr[j-1])break;
        
        int maxi=INT_MIN, mini=INT_MAX;
        for(int x=i;x<=j;x++){
            maxi=max(maxi, arr[x]);
            mini=min(mini, arr[x]);
        }
        
       int start = 0, end = n-1;

        while(start<i && arr[start]<=mini)start++; 
        while(end>j && arr[end]>=maxi)end--;
        return {start, end};
    }
};