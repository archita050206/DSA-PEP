#include<map>
#include<vector>
#include <algorithm>
using namespace std;
string read(int n, vector<int> book, int target)
{
    // Brute Force: 
    // TC= O(n^2)
    // SC= O(n)
   
    // int len=book.size();
    // for(int i=0;i<len;i++){
    //     for(int j=i+1;j<len;j++){
    //         if((book[i]+book[j])==target)return "YES";
    //     }
    // }
    // return "NO";

    // Hashing: 
    //TC= O(n)
    //SC= O(n)

    // int len=book.size();
    // map<int,int>mp;
    // for(int i=0;i<len;i++){
    //     int diff=target-book[i];

    //    if(mp.count(diff))return "YES";
    //    else{
    //        mp[book[i]]=i;
    //    }
    // }
    // return "NO";

    // 2 POINTER : FIRST SORT 
    //TC = O(nlogn)
    //SC = O(1)

    int len=book.size();
    sort(book.begin(), book.end());
    int i=0;
    int j=len-1;
    while(i<j){
        if(book[i]+book[j]==target)return "YES";
        else if (book[i]+book[j]<target)i++;
        else j--;
    }
    return "NO";
    
}
