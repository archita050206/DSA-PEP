#include<iomanip>
#include<vector>
#include<climits>
#include<algorithm>
#include<cmath>
using namespace std;
class Solution {
public:
    long long getHours(vector<int>& piles, int k){
        long long hours=0;
        for(int i: piles){
       
        hours+=(int)ceil((double)i/k);
        //hours += (i + k - 1) / k;
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int key) {
        int l=1;
        int h=*max_element(piles.begin(), piles.end());
        int ans=h;
        while(l<=h){
            int mid=(l+h)/2;
           long long hrs=getHours(piles,mid);
           if(hrs<=key){
            h=mid-1;
            ans=mid;
           }
           else{
            l=mid+1;
           }
        }
        return ans;
    }
};