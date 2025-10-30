#include <vector>
#include<climits>
using namespace std;
class Solution {
public:
int gcd(int a, int b){
    if(a==0)return b;
    return gcd(b%a,a);
}
    int findGCD(vector<int>& nums) {
        int maxi=INT_MIN,mini=INT_MAX;
        for(int i: nums){
            maxi=max(maxi,i);
            mini=min(mini,i);
        }
        return gcd(mini,maxi);

    }
};