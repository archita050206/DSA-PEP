#include<vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        // unordered_set<int>st;
        // for(int i: nums){
        //     st.insert(i%value);

        // }
        // for(int i=0;i<nums.size();i++){
        //     if(!st.count(i))return i;
        // }
        // return -1;
        unordered_map<int,int>mp;
        for(int i: nums){
            int rem=((i%value)+value)%value;
            mp[rem]++;
        }
        int i=0;
        while(true){
            int rem=((i%value)+value)%value;
            if(mp[rem]>0)mp[rem]--;
            else return i;
            i++;
        }
        return -1;
    }
};