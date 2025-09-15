#include<vector>
#include<string>
using namespace std;
long long M=1337;
class Solution {
public:
long long modPow(long long a, long long b){
    long long res=1;
    while(b>0){

        if(b&1)res=(res*a)%M;
        a=(a*a)%M;
        b=b>>1;
    }
    return res;
}
    int superPow(int a, vector<int>& b) {
        if(b.empty())return 1;
        int last=b.back();
        b.pop_back();
        long long A=modPow(superPow(a,b),10);
        long long B=modPow(a,last);
        return (A*B)% M;
    }
};