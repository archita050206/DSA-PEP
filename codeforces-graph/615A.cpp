#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>vis(m+1);
    for(int i=0;i<n;i++){
        int s;
        cin>>s;
        for(int i=0;i<s;i++){
            int val;
            cin>>val;
            vis[val]=true;
        }
    }
    for(int i=1;i<=m;i++){
        if(!vis[i])
        {cout<<"NO";
        return 0;
        }
    }
    cout<<"YES";

    return 0;

}