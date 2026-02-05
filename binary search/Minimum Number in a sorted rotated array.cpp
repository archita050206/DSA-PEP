class Solution {
  public:
    // Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high) {
        // Your code here
        //int l=0,n=sizeof(arr)/sizeof(arr[0]),h=n-1;
        int ans=0;
        while(low<high){
            int mid=low+(high-low)/2;
            if(arr[mid]>arr[high]){
                low=mid+1;
            }
            else{
                
                high=mid;
                
            }
        }
        return arr[high];
    }
};