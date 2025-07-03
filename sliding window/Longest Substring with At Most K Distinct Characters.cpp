#include<map>
#include<climits>
using namespace std;
int kDistinctChars(int k, string &str)
{
    // Write your code here
    int i=0,j=0,cnt=0,maxi=INT_MIN;
    int n=str.length();
    map<char,int>mp;
    while(j<n){
        mp[str[j]]++;
        
        if(mp.size()<=k){
            
            maxi=max(maxi,j-i+1);
            
        }
        else if(mp.size()>k){
            mp[str[i]]--;
            if(mp[str[i]]==0)mp.erase(str[i]);
            i++;
        }
        j++;

    }
    return maxi;
}


