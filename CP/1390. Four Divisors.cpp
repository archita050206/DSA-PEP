#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<bool>isPrime(maxi+1,true);
        isPrime[0]=isPrime[1]=false;
        for(int i=2;i*i<=maxi;i++){
            if(isPrime[i]){
                for(long long j=i*i;j<=maxi;j+=i)isPrime[j]=false;
            }
        }
        int ans=0;
        for(int val:nums){
            int sum=0;
            int cb=round(cbrt(val));
            if(cb*cb*cb==val && isPrime[cb]){
                sum=1+cb+(cb*cb)+val;
                ans+=sum;
            }
            else{
                for(int i=2;i*i<=val;i++){
                    if(val%i==0){
                        int q=val/i;
                        if(i!=q && isPrime[i] && isPrime[q]){
                            sum=1+val+i+q;
                            ans+=sum;
                        }
                    }
                }
            }
        }
        return ans;
    }
};