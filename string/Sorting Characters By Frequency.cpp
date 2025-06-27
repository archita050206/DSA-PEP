#include<string>
#include<vector>
#include<algorithm>
#include<map>

// take a map, store freq, store map in a vector of pairs, sort vector freq in desc order, create string
// TC= O(n logn)
// SC= O(256) ~ O(1) -> since the map can store at most 256 characters (ascii series)

using namespace std;
string sortByFrequency(int n, string& s)
{
	// Write Your Code here
	map<char,int>mp;
	for(char c: s){
		mp[c]++;
	}
	vector<pair<char,int>>v(mp.begin(), mp.end());
	 sort(v.rbegin(), v.rend());
    //, [](const pair<char,int>&a,const pair<char,int> &b){
	// 	return a.second>b.second;
	// });
	string ans="";
	for(auto p:v){
		ans+=string(p.second,p.first);
	}
	return ans;
}

