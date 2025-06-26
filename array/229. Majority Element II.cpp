#include<vector>
#include<unordered_map>
using namespace std;

// TC= O(n) {Moore's Voting Algorithm}->
//  whenever count is 0, increment the count to 1 and upgrade the majority element 
//  else check if arr[i] and maj is same, else decrement by -1 
// SC= O(1)
// first pass gives me the lements, second pass gives me the true frequencies

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // unordered_map<int,int>mp;
        // for(int i: nums){
        //     mp[i]++;
        // }
        // vector<int>ans;
        // int n=(nums.size())/3;
        // for(auto pair: mp){
        //     if(pair.second>n)ans.push_back(pair.first);
        // }
        // return ans;

        int c1=0,c2=0,maj1=0,maj2=1;
        for(int i: nums){
            if(maj1==i)c1++;
            else if(maj2==i)c2++;
            else if(c1==0){
                c1=1;
                maj1=i;
            }
            else if(c2==0){
                c2=1;
                maj2=i;
            }
            
            else{
                c1--;
                c2--;
            }
        }
        c1=c2=0;
        for(int i:nums){
            if(maj1==i)c1++;
            else if(maj2==i)c2++;
        }
        int n=(nums.size())/3;
        vector<int>ans;
        if(c1>n)ans.push_back(maj1);
        if(c2>n)ans.push_back(maj2);
        return ans;
    }
};