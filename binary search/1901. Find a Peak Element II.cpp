#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int maxEle(vector<vector<int>>& mat, int col,int n){
        int maxi=INT_MIN,idx=-1;
        for(int i=0;i<n;i++){
            if(mat[i][col]>maxi){
                maxi=mat[i][col];
                idx=i;
            }
        }
        return idx;

    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int l=0,h=m-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int row=maxEle(mat,mid,n);
            int left=mid-1<0?-1:mat[row][mid-1];
            int right=mid+1>=m?-1:mat[row][mid+1];
            if(mat[row][mid]>left && mat[row][mid]>right)return vector<int>{row,mid};
            else if(mat[row][mid]<left){
                h=mid-1;
            }
            else l=mid+1;
        }
        return vector<int>{-1,-1};
    }
};