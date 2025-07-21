/*

Problem statement
Given an array of integers, find the Kth largest sum subarray For example, given the array [1, -2, 3, -4, 5] and K = 2, the 2nd largest sum subarray would be [3, -4, 5], which has a sum of 4.

Please note that a subarray is the sequence of consecutive elements of the array.
*/

#include<queue>
using namespace std;
int getKthLargest(vector<int> &arr, int k)
{
	
	priority_queue<int,vector<int>,greater<int>>pq;
	for(int i=0;i<arr.size();i++){
		int sum=0;
		for(int j=i;j<arr.size();j++){
			sum+=arr[j];
			pq.push(sum);
			if(pq.size()>k)pq.pop();
		}
	}
	 
	return pq.top();

}