#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int c=0;
        for(int i: costs){
            
            if(i>coins){
                return c;
            }
            c++;
            coins=coins-i;
        }
        return c;
    }
};