#include<stack>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i:asteroids){
            while(!st.empty() && st.top()>0 && i<0){
                int sum=i+st.top();
                if(sum==0){
                    i=0;
                    st.pop();
                }
                else if(sum<0){
                    st.pop();
                }
                else if(sum>0){
                    i=0;

                }
            }
            if(i!=0){
                st.push(i);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            int x=st.top();
            st.pop();
            ans.push_back(x);
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};