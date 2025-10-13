#include <vector>
#include<stack>

using namespace std;
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>ans(prices.size(),-1);
        stack<int>st;

        for(int i=prices.size()-1;i>=0;i--){
            while(!st.empty() && prices[i]<st.top())st.pop();
            if(!st.empty() && prices[i]>=st.top())ans[i]=st.top();
            st.push(prices[i]);
        }
        for(int i=0;i<prices.size();i++){
            if(ans[i]!=-1)prices[i]-=ans[i];
        }
        return prices;
    }
};