/*
For Example:
For the array [ 4, 7, 9, 10] and ‘k’=2
In the first step, we can choose the last bag. So the answer will be 10 and the array will be [4, 7, 9, 5].
In the second step, we can choose the second last bag. So the answer will be 19 and the array will be [4, 7, 4, 5].
So the final output will be 19.
*/

#include <bits/stdc++.h> 
using namespace std;
int maximumChocolates(vector<int> &arr, int k){
    
    priority_queue<int>pq(arr.begin(),arr.end());
    int sum=0;
    for(int i=0;i<k;i++){
        int x=pq.top();
        sum+=x;
        pq.pop();
        pq.push(x/2);
    }
    return sum;
}