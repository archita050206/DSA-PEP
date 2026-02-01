#include <vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        int len=1, maxi=INT_MIN;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]+1==arr[i+1]){
                len++;
                maxi=max(maxi,len);
            }
            else if(arr[i]==arr[i+1])continue;
            else len=1;
        }
        return maxi==INT_MIN?1:maxi;;
    }
};