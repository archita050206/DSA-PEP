// User function Template for C++

class Solution {
  public:
    int isRepresentingBST(int arr[], int N) {
        // code here
        if(N==0)return 0;
        for(int i=1;i<N;i++){
            if(arr[i-1]>=arr[i])return false;
        }
        return true;
    }
};