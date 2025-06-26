#include <unordered_map>
#include <vector>
using namespace std;
int findDuplicate(vector<int> &arr) 
{
	// unordered_map<int,int>mp;
    // for(int i: arr){
    //     mp[i]++;
    // }
    // for(auto pair: mp){
    //     if(pair.second>1)return pair.first;
    // }
    // return -1;

    int n=arr.size();
    int s=0;
    int sum=0;
    for(int i=0;i<n;i++){
        s+=arr[i]; // can also use n*(n+1)/2
    }
    for(int i=1;i<n;i++){
        sum+=i;
    }
    
    return s-sum;
}
