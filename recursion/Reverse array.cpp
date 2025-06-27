#include<iostream>
using namespace std;
void revArr( int arr[], int s, int e){
    if(s>=e)return;
    swap(arr[s],arr[e]);
    revArr(arr,s+1,e-1);
}