#include<string>
#include<vector>
#include<algorithm>
#include<map>

// take a map, store freq, store map in a vector of pairs, sort vector freq in desc order, create string

using namespace std;
string sortByFrequency(int n, string& s)
{
	map<char,int>mp;
	for(char c: s){
		mp[c]++;
	}
	vector<pair<char,int>>v(mp.begin(), mp.end());
	sort(v.begin(), v.end(), [](const pair<char,int>&a,const pair<char,int> &b){
		return a.second>b.second;
	});
	string ans="";
	for(auto p:v){
		ans+=string(p.second,p.first);
	}
	return ans;
}
