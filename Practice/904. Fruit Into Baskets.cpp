#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0,n=fruits.size(),len=0;
        unordered_map<int,int>mp;
        while(j<n){
            mp[fruits[j]]++;
            if(mp.size()<=2){
                len=max(len,j-i+1);
            }
            while(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0)mp.erase(fruits[i]);
                i++;
            }
            j++;
        }
        return len;
    }
};