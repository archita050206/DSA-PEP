#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int getDays(vector<int>&weights, int val){
        int sum=0,cnt=1;
        for(int i: weights){
            if(sum+i>val){
                cnt++;
                sum=i;
            }
            else sum+=i;
        }
        return cnt;
    }
    int shipWithinDays(vector<int>& weights, int threshold) {
        int sum=0;
        for(int i: weights)sum+=i;
        int l=*max_element(weights.begin(), weights.end()),h=sum,ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int days=getDays(weights, mid);
            if(days<=threshold){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;

    }
};