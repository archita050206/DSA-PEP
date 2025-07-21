class Solution {
  public:
    int heapHeight(int n, int arr[]) {
        // code here
        if(n==1)return 1;
        int cnt=0;
        while(n>1){
            cnt++;
            n/=2;
            
        }
        return cnt;
    }
};