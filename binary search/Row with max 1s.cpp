// User function template for C++
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int maxi=0,idx=-1;
        for(int i=0;i<n;i++){
            sort(mat[i].begin(),mat[i].end());
            int l=0,h=m-1,ans=-1;
            while(l<=h){
                int mid=l+(h-l)/2;
                if(mat[i][mid]==1){
                    ans=mid;
                    h=mid-1;
                }
                else l=mid+1;
            }
            int cnt=ans==-1?0:m-ans;
            if(cnt>maxi){
                maxi=cnt;
                idx=i;
            }
        }
        return idx;
    }
};