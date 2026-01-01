class Solution {
  public:
    bool solver(int i,vector<int>&arr, int sum1, int sum2,int target){
        if(i>=(arr.size()))return (sum1==target)&&(sum2==target);
        if(sum1>target || sum2>target)return false;
        bool op1=solver(i+1,arr,sum1+arr[i], sum2, target);
        bool op2=solver(i+1, arr,sum1, sum2+arr[i], target);
        return op1||op2;
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int target=0;
        for(int i: arr){
            target+=i;
            
        }
        if(target%2!=0)return false;
        // int sum1=0,sum2=0;
        // return solver(0,arr,sum1,sum2,target/2);
        vector<bool>dp((target/2)+1,false);
        dp[0]=true;
        for(int i=0;i<arr.size();i++){
            for(int j=target/2;j>=arr[i];j--){
                dp[j]=dp[j]||dp[j-arr[i]];
            }
        }
        return dp[target/2];
    }
};