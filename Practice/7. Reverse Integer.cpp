#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int k=x, rev=0;
        while(x!=0){
            int d=x%10;
            if(rev>INT_MAX/10 || (rev==INT_MAX && d>7))return 0;
            if(rev<INT_MIN/10 || (rev==INT_MIN && d<-8))return 0;
            rev=rev*10+d;
            x=x/10;
        }
        return rev;
    }
};