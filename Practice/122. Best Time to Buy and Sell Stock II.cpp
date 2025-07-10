
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())return 0;
        int n=prices.size();
        if(n==1)return 0;
        int sum=0;
        for(int i=1;i<n;i++){
            if(prices[i-1]<prices[i]){
                sum+=prices[i]-prices[i-1];
            }
        }
        return sum;
    }
};