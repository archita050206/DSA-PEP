#include<vector>
using namespace std;
class Solution {
public:
    int count(vector<vector<int>>& matrix, int val){
        int r=0,c=matrix[0].size()-1;
        int cnt=0;
        while(r<matrix.size() && c>=0){
            if(matrix[r][c]<=val){
                cnt+=c+1;
                r++;
            }
            else c--;
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int l=matrix[0][0], h=matrix[rows-1][cols-1];
        while(l<h){
            int mid=l+(h-l)/2;
            int cnt=count(matrix, mid);
            if(cnt<k)l=mid+1;
            else h=mid;
        }
        return h;
    }
};