#include<vector>

using namespace std;
class Solution {
  public:
  
    int solver(int i, vector<int>& arr, int target, int n){
        if(i==n){
            if(target==0)return 1;
            else return 0;
        }
        return solver(i+1, arr, target-arr[i], n)+solver( i+1,arr, target,n);
    }
  
    int perfectSum(vector<int>& arr, int target) {
      
        int n=arr.size();
        return solver(0,arr,target,n);
    }
};