
#include<vector>
#include<climits>
using namespace std;

/*
keep maintining the minimum price we get, if the price is more than the min price then that means there is a scope for profit
*/

class Solution {
public:
     int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int profit=0;
        for(int p: prices){
            if(p<minPrice){
                minPrice=p;
            }
            else if(p>=minPrice){
                profit=max(profit, p-minPrice);
            }
        }
        return profit;
    }
};