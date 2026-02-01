#include <vector>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // any element has to be greater than or equal to the largest element on it right half
        int n=arr.size();
        int i=n-1,maxi=INT_MIN;
        vector<int>ans;
        while(i>=0){
            if(arr[i]>=maxi){
                ans.push_back(arr[i]);
                maxi=arr[i];
            }
            i--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};