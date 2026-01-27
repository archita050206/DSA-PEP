// User function Template for C++

class Solution {
  public:
    // Function to merge two nodes a and b.
    int find(int par[], int v){
        if(par[v]==v)return v;
        return par[v]=find(par,par[v]);
    }
    void union_(int a, int b, int par[], int rank1[]) {
        // code here
        int pa=find(par,a);
        int pb=find(par,b);
        if(pa==pb)return;
        else if(rank1[pa]<rank1[pb]){
            par[pa]=pb;
        }
        else if(rank1[pb]<rank1[pa]){
            par[pb]=pa;
        }
        else{
            par[pa]=pb;
            rank1[pb]++;
        }
    }

    // Function to check whether 2 nodes are connected or not.
    bool isConnected(int x, int y, int par[], int rank1[]) {
        
        // code here
        int pa=find(par,x);
        int pb=find(par,y);
        if(pa==pb)return true;
        return false;
        
    }
};