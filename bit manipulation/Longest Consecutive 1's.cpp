#include<algorithm>
using namespace std;
class Solution {
  public:
    int maxConsecutiveOnes(int n) {
        
        int maxi=0,cnt=0;
        while(n!=0){
            if((n&1)==1){
                cnt++;
                maxi=max(cnt,maxi);
                
                
            }
            else if((n&1)==0){
                cnt=0;
            }
            n=n>>1;
            
        }
        return maxi;
    }
};
