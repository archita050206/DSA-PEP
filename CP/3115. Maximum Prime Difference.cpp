#include <vector>
#include<cmath>
using namespace std;
class Solution {
public:
bool isPrime(int n){
    if(n<=1)return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}
    int maximumPrimeDifference(vector<int>& nums) {
        int i=0,j=0,b=0;
        for(i=0;i<nums.size();i++){
            if(isPrime(nums[i]))break;
        }
        for(j=0;j<nums.size();j++){
            if(isPrime(nums[j]))b=j;
        }
        return abs(i-b);
    }
};