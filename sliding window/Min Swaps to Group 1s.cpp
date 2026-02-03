#include<vector>
#include<climits>
using namespace std;
class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // Complete the function
        int cnt=0,cz=0,mini=INT_MAX;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==1)cnt++;
        }
        int i=0,j=0,n=arr.size();
        while(j<n){
            if(arr[j]==0)cz++;
            int len=j-i+1;
            if(len==cnt){
                mini=min(mini,cz);
                if(arr[i]==0){
                    cz--;
                    i++;
                }
                else i++;
            }
            j++;
        }
        return mini==INT_MAX?-1:mini;
    }
};