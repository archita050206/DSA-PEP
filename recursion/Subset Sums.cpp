#include<vector>
#include<string>

using namespace std;

//tc-> 2^n
// sc-> O(2^n) -> for vector
// sc-> O(n) -> for recursion(levels)
// start from i=1 to i=n, inslude an element, exclude another element, get sum

class Solution {
  public:
  
  void solve(int i, vector<int>& arr, int sum,vector<int>& ans){
     if(i>=arr.size()){
         ans.push_back(sum);
         return;
     }
      solve(i+1,arr,sum+arr[i],ans);
      
      solve(i+1,arr,sum,ans);
  }
  
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>ans;
        
       
    solve(0, arr, 0, ans);
    return ans;
    }
};