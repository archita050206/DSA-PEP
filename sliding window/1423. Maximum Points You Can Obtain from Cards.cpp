
#include<vector>
#include<algorithm>
using namespace std;class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size(),ls=0,rs=0;
        for(int i=0;i<k;i++){
            ls+=cardPoints[i];
        }
        int rindex=n-1;
        int maxi=ls;
        for(int i=k-1;i>=0;i--){
            ls-=cardPoints[i];
            rs+=cardPoints[rindex];
            rindex--;
            maxi=max(maxi,ls+rs);
        }
        return maxi;
    }
};