#include<queue>
#include<vector>
using namespace std;
bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	// Write your code here
	vector<vector<int>>adj(v);
	queue<int>q;
	vector<int>ans;
	for(int i=0;i<e;i++){
		int u1=edges[i][0];
		int u2=edges[i][1];
		adj[u1].push_back(u2);
	}
	vector<int>indegree(v);
	for(int i=0;i<v;i++){
		for(int neighbour: adj[i]){
			indegree[neighbour]++;
		}
	}
	for(int i=0;i<v;i++){
		if(indegree[i]==0)q.push(i);
	}
	while(!q.empty()){
		int node=q.front();
		q.pop();
		ans.push_back(node);
		for(int neighbour: adj[node]){
			indegree[neighbour]--;
			if(indegree[neighbour]==0)q.push(neighbour);
		}
	}
	if(ans.size()<v)return true;
	return false;
}
