#include <vector>
using namespace std;
class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        int i=0,j=0,k=0,n1=arr1.size(), n2=arr2.size(), n3=arr3.size();
        vector<int>ans;
        while(i<n1 && j<n2 && k<n3){
            if(arr1[i]==arr2[j] && arr1[i]==arr3[k]){
                ans.push_back(arr1[i]);
                
                int val=arr1[i];
                i++;j++;k++;
                 while (i < n1 && arr1[i] == val) i++;
                while (j < n2 && arr2[j] == val) j++;
                while (k < n3 && arr3[k] == val) k++;
                
            }
            else if(arr1[i]<=arr2[j] && arr1[i]<=arr3[k]){
                i++;
            }
            else if(arr3[k]<=arr2[j] && arr3[k]<=arr1[i]){
                k++;
            }
            else if(arr2[j]<=arr1[i] && arr2[j]<=arr3[k]){
                j++;
            }
            
        }
        return ans;
    }
};