#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	vector<int>ans;
	vector<vector<int>>adj(n+1);
	for(int i=0;i<m;i++){
		
			int u=edges[i].first;
			int v=edges[i].second;
			adj[u].push_back(v);
			adj[v].push_back(u);
		
	}
	vector<int>parent(n+1,-1);
	vector<bool>visited(n+1,false);
	queue<int>q;
	q.push(s);
	visited[s]=true;
	
	while(!q.empty()){
		int node=q.front();
		q.pop();
		for(int i: adj[node]){
			if(!visited[i]){
				visited[i]=true;
				parent[i]=node;
				q.push(i);
			}
		}
	}
	
	int curr=t;
	while(curr!=-1){
		ans.push_back(curr);
		curr=parent[curr];
		
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
