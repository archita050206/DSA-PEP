#include<iomanip>
#include<vector>
#include<climits>
#include<algorithm>
#include<cmath>
using namespace std;

// the minimum number of piles koko can eat is 1, and the max is the max number in the array, so koko can eat any number from 1 to the max. We've got a search space then, now apply binary search

class Solution {
public:
    long long getHours(vector<int>& piles, int k){
        long long hours=0;
        for(int i: piles){
            hours+=(int)ceil((double)i/k);
        }
        return hours;
    }
    int maxVal(vector<int>& piles){
        int maxi=INT_MIN;
        for(int i: piles){
            maxi=max(maxi,i);
        }
        return maxi;
    }
    int minEatingSpeed(vector<int>& piles, int key) {
        int l=1;
        int h=maxVal(piles);
        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            long long hrs=getHours(piles,mid);
            if(hrs<=key){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};