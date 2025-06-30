#include<vector>
#include<string>

using namespace std;
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
        
        vector<int>v;
       
        int n=arr.size();
    solve(0, arr, 0, ans);
    return ans;
    }
};