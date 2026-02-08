#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int getCount(vector<int>& bloomDay, int val, int m, int k){
        int cnt=0,total=0;
        for(int i: bloomDay){
            if(i<=val){
                cnt++;
            }
            else {
                total+=(cnt/k);
                cnt=0;
            }
        }
        total+=cnt/k;
        return total;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long need = (long long)m * k;
        if (need > bloomDay.size()) return -1;
        
        int l=*min_element(bloomDay.begin(), bloomDay.end());
        int h=*max_element(bloomDay.begin(), bloomDay.end());

        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int cnt= getCount(bloomDay, mid, m,k);
            
             if(cnt>=m){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
            
        }
        return ans;
    }
};