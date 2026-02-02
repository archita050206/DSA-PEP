#include<vector>
#include<algorithm>
using namespace std;
class Solution {
  public:
    int mergeSort(vector<int>&arr, int l, int mid, int h){
        int n1=mid-l+1,n2=h-mid;
        vector<int>left(n1),right(n2);
        for(int i=0;i<n1;i++){
            left[i]= arr[l+i];
        }
        for(int i=0;i<n2;i++){
            right[i]=arr[mid+i+1];
        }
        int i=0,j=0,k=l,cnt=0;
        while(i<n1 && j<n2){
            if(left[i]<=right[j]){
                arr[k]=left[i];
                k++;
                i++;
            }
            else{
                arr[k]=right[j];
                j++;
                k++;
                cnt+=(n1-i);
            }
        }
        while(i<n1){
            arr[k]=left[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k]=right[j];
            j++;k++;
        }
        return cnt;
        
    }
    int merge(vector<int>&arr, int l, int h){
        int cnt=0;
        if(l>=h)return cnt;
        int mid=(l+h)/2;
        cnt+=merge(arr,l,mid);//--> sort the left half
        cnt+=merge(arr,mid+1,h);//--> sort the right half
        cnt+=mergeSort(arr,l,mid,h);//--> combine both halves
        return cnt;
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        return merge(arr,0,n-1);
        
    }
};