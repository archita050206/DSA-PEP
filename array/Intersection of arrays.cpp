#include <bits/stdc++.h> 
using namespace std;
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// solve like merging 2 arrays
    
	vector<int>v;
	int i=0,j=0;
	while(i<n && j<m){
		if(arr1[i]==arr2[j]){
			v.push_back(arr1[i]);
			i++;
			j++;
		}
		else if(arr1[i]<arr2[j]){
			i++;
		}
		else if(arr2[j]<arr1[i]){
			j++;
		}
	}
	return v;
}