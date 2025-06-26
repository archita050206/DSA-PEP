#include<vector>
#include<unordered_map>
using namespace std;

// TC= O(n) {Moore's Voting Algorithm}->
//  whenever count is 0, increment the count to 1 and upgrade the majority element 
//  else check if arr[i] and maj is same, else decrement by -1 
// SC= O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int,int>mp;
        // for(int a: nums){
        //     mp[a]++;
        // }
        // int n=nums.size()/2;
        // for(auto pair: mp){
        //     if(pair.second>n)return pair.first;
        // }
        // return -1;

        int count=0, maj=0;
        for(int i: nums){
            if(count==0){
                count=1;
                maj=i;
            }
            else (i==maj)?count++:count--;
        }
        return maj;
    }
};