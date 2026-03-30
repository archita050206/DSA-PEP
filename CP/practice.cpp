#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int idx=-1,i=0,j=0,sum=0,mini=INT_MAX;
    while(j<n){
        sum+=arr[j];
        if(j-i+1==k){
            if(sum<mini){
                mini=sum;
                idx=i;
            }
            sum-=arr[i];
            i++;
        }
        j++;
    }
    cout<<(idx+1);
    return 0;
}