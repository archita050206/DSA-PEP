#include <bits/stdc++.h> 
using namespace std;
int occursOnce(vector<int> &a, int n){
	// TC= O(n)
	// SC= O(n)
	// unordered_map<int,int> mp;
	// for(int i: a){
	// 	mp[i]++;
	// }
	// for( auto pair: mp){
	// 	if(pair.second==1)return pair.first;
	// }
	// return -1;


	//TC= O(n)
	//SC= O(1)
	int ans=0;
	for(int i=0;i<a.size();i++){
		ans=ans^a[i];
	}
	return ans;
}
