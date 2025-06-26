#include<vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // needs attention
        int n=arr.size();
        int maxi=0;
        int sum=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0){
                maxi=i+1;
            }
            if(mp.count(sum)){
                maxi=max(maxi,i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }
        }
        return maxi;
    }
};