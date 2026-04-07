#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;
int main(){
   int n;
   cin>>n;
   vector<int>p(n),a(n),b(n);
   
   for(int i=0;i<n;i++)cin>>p[i];
   for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    vector<priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>>>pq(4);
    for(int i=0;i<n;i++){
        pq[a[i]].push({p[i],i});
        if(a[i]!=b[i])pq[b[i]].push({p[i],i});
    }
    int m;
    cin>>m;
    vector<bool>vis(n,false);
    for(int i=0;i<m;i++){
        int c;
        cin>>c;
        while(!pq[c].empty() && vis[pq[c].top().second])pq[c].pop();
        if(pq[c].empty())cout<<-1<<" ";
        else{
            int price=pq[c].top().first;
            int idx=pq[c].top().second;
            pq[c].pop();
            vis[idx]=true;
            cout<<price<<" ";
        }
    }
   
    return 0;
}