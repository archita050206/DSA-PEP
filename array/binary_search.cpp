#include <vector>
using namespace std;
class Solution {
  public:
    // Function to find element in sorted array
    // arr: input array
    // k: element to be searched
    bool searchInSorted(vector<int>& arr, int k) {

        // Your code here
        int l=0;
        int h=arr.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]==k){
                return true;
            }
            else if(k<arr[mid]){
                h=mid-1;
            }
            else if(k>arr[mid]){
                l=mid+1;
            }
        }
        return false;
    }
};